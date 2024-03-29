#include "pch.h"
#include "AABB3.h"
#include <assert.h>
#include "CommonStuff.h"
Vector3 AABB3::corner(int i)const
{
	//左手坐标系
	//0正面左下角、1正面右下角、2正面左上角、3正面右下角
	//4背面左下角、5背面右下角、6背面左上角、7背面右下角
	assert(i >= 0);
	assert(i <= 7);
	//if (i == 0)
	//	return Vector3(min.x, min.y, min.z);
	//if (i == 1)
	//	return Vector3(max.x, min.y, min.z);
	//if (i == 2)
	//	return Vector3(min.x, max.y, min.z);
	//if (i == 3)
	//	return Vector3(min.x, min.y, min.z);
	//if (i == 4)
	//	return Vector3(min.x, min.y, min.z);
	//if (i == 5)
	//	return Vector3(min.x, min.y, min.z);
	//if (i == 6)
	//	return Vector3(min.x, min.y, min.z);
	//if (i == 7)
	//	return Vector3(min.x, min.y, min.z);

	return Vector3((i & 1) ? max.x : min.x, (i & 2) ? max.y : min.y, (i & 4) ? max.z : min.z);
}

void AABB3::empty()
{
	const float kBigNumber = 1e37f;
	min.x = min.y = min.z = kBigNumber;
	max.x = max.y = max.z = -kBigNumber;
}

bool AABB3::isEmpty() const
{
	return (min.x > max.x) || (min.y > max.y) || (min.z > max.z);
}

void AABB3::add(const Vector3 &p)
{
	if (p.x < min.x)
		min.x = p.x;
	if (p.x > max.x)
		max.x = p.x;

	if (p.y < min.y)
		min.y = p.y;
	if (p.y > max.y)
		max.y = p.y;

	if (p.z < min.z)
		min.z = p.z;
	if (p.z > max.z)
		max.z = p.z;

}

void AABB3::add(const AABB3 &box)
{
	if (box.min.x < min.x)
		min.x = box.min.x;
	if (box.max.x > max.x)
		max.x = box.max.x;

	if (box.min.y < min.y)
		min.y = box.min.y;
	if (box.max.y > max.y)
		max.y = box.max.y;

	if (box.min.z < min.z)
		min.z = box.min.z;
	if (box.max.z > max.z)
		max.z = box.max.z;
}

bool AABB3::contains(const Vector3 &p) const
{
	return (p.x >= min.x) && (p.x <= max.x) &&
		   (p.y >= min.y) && (p.y <= max.y) &&
		   (p.z >= min.z) && (p.z <= max.z);

}

void AABB3::setToTransformedBox(const AABB3 &box, const Matrix4x3 &m)
{
	if (box.isEmpty())
	{
		empty();
		return;
	}
	min = max = getTranslation(m);

	if (m.m11 > 0.0f)
	{
		min.x += m.m11*box.min.x;
		max.x += m.m11*box.max.x;
	}
	else
	{
		min.x += m.m11*box.max.x;
		max.x += m.m11*box.min.x;
	}

	if (m.m12 > 0.0f)
	{
		min.y += m.m12*box.min.x;
		max.y += m.m12*box.max.x;
	}
	else
	{
		min.y += m.m12*box.max.x;
		max.y += m.m12*box.min.x;
	}

	if (m.m13 > 0.0f)
	{
		min.z += m.m13*box.min.x;
		max.z += m.m13*box.max.x;
	}
	else
	{
		min.z += m.m13*box.max.x;
		max.z += m.m13*box.min.x;
	}

	if (m.m21 > 0.0f)
	{
		min.x += m.m21*box.min.y;
		max.x += m.m21*box.max.y;
	}
	else
	{
		min.x += m.m21*box.max.y;
		max.x += m.m21*box.min.y;
	}

	if (m.m22 > 0.0f)
	{
		min.y += m.m22*box.min.y;
		max.y += m.m22*box.max.y;
	}
	else
	{
		min.y += m.m22*box.max.y;
		max.y += m.m22*box.min.y;
	}

	if (m.m23 > 0.0f)
	{
		min.z += m.m23*box.min.y;
		max.z += m.m23*box.max.y;
	}
	else
	{
		min.z += m.m23*box.max.y;
		max.z += m.m23*box.min.y;
	}

	if (m.m31 > 0.0f)
	{
		min.x += m.m31*box.min.z;
		max.x += m.m31*box.max.z;
	}
	else
	{
		min.x += m.m31*box.max.z;
		max.x += m.m31*box.min.z;
	}

	if (m.m32 > 0.0f)
	{
		min.y += m.m32*box.min.z;
		max.y += m.m32*box.max.z;
	}
	else
	{
		min.y += m.m32*box.max.z;
		max.y += m.m32*box.min.z;
	}

	if (m.m33 > 0.0f)
	{
		min.z += m.m33*box.min.z;
		max.z += m.m33*box.max.z;
	}
	else
	{
		min.z += m.m33*box.max.z;
		max.z += m.m33*box.min.z;
	}
}


Vector3 AABB3::closestPointTo(const Vector3 &p) const
{
	Vector3 r;
	if (p.x < min.x)
	{
		r.x = min.x;
	}
	else if (p.x > max.x)
	{
		r.x = max.x;
	}
	else
	{
		r.x = p.x;
	}

	if (p.y < min.y)
	{
		r.y = min.y;
	}
	else if (p.y > max.y)
	{
		r.y = max.y;
	}
	else
	{
		r.y = p.y;
	}

	if (p.z < min.z)
	{
		r.z = min.z;
	}
	else if (p.z > max.z)
	{
		r.z = max.z;
	}
	else
	{
		r.z = p.z;
	}
	return r;
}

float   AABB3::rayIntersect(
	const Vector3 &rayOrg,      // orgin of the ray
	const Vector3 &rayDelta,    // length and direction of the ray
	Vector3 *returnNormal       // optionally, the normal is returned
) const {

	// We'll return this huge number if no intersection

	const float kNoIntersection = 1e30f;

	// Check for point inside box, trivial reject, and determine parametric
	// distance to each front face

	bool inside = true;

	float xt, xn;
	if (rayOrg.x < min.x) {
		xt = min.x - rayOrg.x;
		if (xt > rayDelta.x) return kNoIntersection;
		xt /= rayDelta.x;
		inside = false;
		xn = -1.0f;
	}
	else if (rayOrg.x > max.x) {
		xt = max.x - rayOrg.x;
		if (xt < rayDelta.x) return kNoIntersection;
		xt /= rayDelta.x;
		inside = false;
		xn = 1.0f;
	}
	else {
		xt = -1.0f;
	}

	float yt, yn;
	if (rayOrg.y < min.y) {
		yt = min.y - rayOrg.y;
		if (yt > rayDelta.y) return kNoIntersection;
		yt /= rayDelta.y;
		inside = false;
		yn = -1.0f;
	}
	else if (rayOrg.y > max.y) {
		yt = max.y - rayOrg.y;
		if (yt < rayDelta.y) return kNoIntersection;
		yt /= rayDelta.y;
		inside = false;
		yn = 1.0f;
	}
	else {
		yt = -1.0f;
	}

	float zt, zn;
	if (rayOrg.z < min.z) {
		zt = min.z - rayOrg.z;
		if (zt > rayDelta.z) return kNoIntersection;
		zt /= rayDelta.z;
		inside = false;
		zn = -1.0f;
	}
	else if (rayOrg.z > max.z) {
		zt = max.z - rayOrg.z;
		if (zt < rayDelta.z) return kNoIntersection;
		zt /= rayDelta.z;
		inside = false;
		zn = 1.0f;
	}
	else {
		zt = -1.0f;
	}

	// Inside box?

	if (inside) {
		if (returnNormal != 0) {
			*returnNormal = -rayDelta;
			returnNormal->normalize();
		}
		return 0.0f;
	}

	// Select farthest plane - this is
	// the plane of intersection.

	int which = 0;
	float t = xt;
	if (yt > t) {
		which = 1;
		t = yt;
	}
	if (zt > t) {
		which = 2;
		t = zt;
	}

	switch (which) {

	case 0: // intersect with yz plane
	{
		float y = rayOrg.y + rayDelta.y*t;
		if (y < min.y || y > max.y) return kNoIntersection;
		float z = rayOrg.z + rayDelta.z*t;
		if (z < min.z || z > max.z) return kNoIntersection;

		if (returnNormal != 0) {
			returnNormal->x = xn;
			returnNormal->y = 0.0f;
			returnNormal->z = 0.0f;
		}

	} break;

	case 1: // intersect with xz plane
	{
		float x = rayOrg.x + rayDelta.x*t;
		if (x < min.x || x > max.x) return kNoIntersection;
		float z = rayOrg.z + rayDelta.z*t;
		if (z < min.z || z > max.z) return kNoIntersection;

		if (returnNormal != 0) {
			returnNormal->x = 0.0f;
			returnNormal->y = yn;
			returnNormal->z = 0.0f;
		}

	} break;

	case 2: // intersect with xy plane
	{
		float x = rayOrg.x + rayDelta.x*t;
		if (x < min.x || x > max.x) return kNoIntersection;
		float y = rayOrg.y + rayDelta.y*t;
		if (y < min.y || y > max.y) return kNoIntersection;

		if (returnNormal != 0) {
			returnNormal->x = 0.0f;
			returnNormal->y = 0.0f;
			returnNormal->z = zn;
		}

	} break;
	}

	// Return parametric point of intersection

	return t;

}


bool    intersectAABBs(
	const AABB3 &box1,
	const AABB3 &box2,
	AABB3 *boxIntersect
) {

	// Check for no overlap

	if (box1.min.x > box2.max.x) return false;
	if (box1.max.x < box2.min.x) return false;
	if (box1.min.y > box2.max.y) return false;
	if (box1.max.y < box2.min.y) return false;
	if (box1.min.z > box2.max.z) return false;
	if (box1.max.z < box2.min.z) return false;

	// We have overlap.  Compute AABB of intersection, if they want it

	if (boxIntersect != 0) {
		boxIntersect->min.x = max(box1.min.x, box2.min.x);
		boxIntersect->max.x = min(box1.max.x, box2.max.x);
		boxIntersect->min.y = max(box1.min.y, box2.min.y);
		boxIntersect->max.y = min(box1.max.y, box2.max.y);
		boxIntersect->min.z = max(box1.min.z, box2.min.z);
		boxIntersect->max.z = min(box1.max.z, box2.max.z);
	}

	// They intersected

	return true;
}


float   intersectMovingAABB(const AABB3 &stationaryBox,const AABB3 &movingBox,const Vector3 &d) 
{

	// We'll return this huge number if no intersection

	const float kNoIntersection = 1e30f;

	// Initialize interval to contain all the time under consideration

	float   tEnter = 0.0f;
	float   tLeave = 1.0f;

	//
	// Compute interval of overlap on each dimension, and intersect
	// this interval with the interval accumulated so far.  As soon as
	// an empty interval is detected, return a negative result
	// (no intersection.)  In each case, we have to be careful for
	// an infinite of empty interval on each dimension
	//

	// Check x-axis

	if (d.x == 0.0f) {

		// Empty or infinite inverval on x

		if (
			(stationaryBox.min.x >= movingBox.max.x) ||
			(stationaryBox.max.x <= movingBox.min.x)
			) {

			// Empty time interval, so no intersection

			return kNoIntersection;
		}

		// Inifinite time interval - no update necessary

	}
	else {

		// Divide once

		float   oneOverD = 1.0f / d.x;

		// Compute time value when they begin and end overlapping

		float   xEnter = (stationaryBox.min.x - movingBox.max.x) * oneOverD;
		float   xLeave = (stationaryBox.max.x - movingBox.min.x) * oneOverD;

		// Check for interval out of order

		if (xEnter > xLeave) {
			swap(xEnter, xLeave);
		}

		// Update interval

		if (xEnter > tEnter) tEnter = xEnter;
		if (xLeave < tLeave) tLeave = xLeave;

		// Check if this resulted in empty interval

		if (tEnter > tLeave) {
			return kNoIntersection;
		}
	}

	// Check y-axis

	if (d.y == 0.0f) {

		// Empty or infinite inverval on y

		if (
			(stationaryBox.min.y >= movingBox.max.y) ||
			(stationaryBox.max.y <= movingBox.min.y)
			) {

			// Empty time interval, so no intersection

			return kNoIntersection;
		}

		// Inifinite time interval - no update necessary

	}
	else {

		// Divide once

		float   oneOverD = 1.0f / d.y;

		// Compute time value when they begin and end overlapping

		float   yEnter = (stationaryBox.min.y - movingBox.max.y) * oneOverD;
		float   yLeave = (stationaryBox.max.y - movingBox.min.y) * oneOverD;

		// Check for interval out of order

		if (yEnter > yLeave) {
			swap(yEnter, yLeave);
		}

		// Update interval

		if (yEnter > tEnter) tEnter = yEnter;
		if (yLeave < tLeave) tLeave = yLeave;

		// Check if this resulted in empty interval

		if (tEnter > tLeave) {
			return kNoIntersection;
		}
	}

	// Check z-axis

	if (d.z == 0.0f) {

		// Empty or infinite inverval on z

		if (
			(stationaryBox.min.z >= movingBox.max.z) ||
			(stationaryBox.max.z <= movingBox.min.z)
			) {

			// Empty time interval, so no intersection

			return kNoIntersection;
		}

		// Inifinite time interval - no update necessary

	}
	else {

		// Divide once

		float   oneOverD = 1.0f / d.z;

		// Compute time value when they begin and end overlapping

		float   zEnter = (stationaryBox.min.z - movingBox.max.z) * oneOverD;
		float   zLeave = (stationaryBox.max.z - movingBox.min.z) * oneOverD;

		// Check for interval out of order

		if (zEnter > zLeave) {
			swap(zEnter, zLeave);
		}

		// Update interval

		if (zEnter > tEnter) tEnter = zEnter;
		if (zLeave < tLeave) tLeave = zLeave;

		// Check if this resulted in empty interval

		if (tEnter > tLeave) {
			return kNoIntersection;
		}
	}

	// OK, we have an intersection.  Return the parametric point in time
	// where the intersection occurs

	return tEnter;
}
