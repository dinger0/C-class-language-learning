#include "pch.h"
#include "Vector3.h"
#include "RotationMatrix.h"
#include "EulerAngles.h"
#include "MathUtil.h"
void RotationMatrix::identity()
{
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}

Vector3 RotationMatrix::inertialToObject(const Vector3 &v) const
{
	return Vector3(m11*v.x + m21 * v.y + m31 * v.z,
				   m12*v.x + m22 * v.y + m32 * v.z,
				   m13*v.x + m23 * v.y + m33 * v.z);
}


Vector3 RotationMatrix::objectToInertial(const Vector3 &v) const
{
	return Vector3(m11*v.x + m12 * v.y + m13 * v.z,
				   m21*v.x + m22 * v.y + m23 * v.z,
				   m31*v.x + m32 * v.y + m33 * v.z);
}

void RotationMatrix::setup(const EulerAngles &orientation)
{
	float sh, ch, sp, cp, sb, cb;
	sinCos(&sh, &ch, orientation.heading);
	sinCos(&sp, &cp, orientation.pitch);
	sinCos(&sb, &cb, orientation.bank);

	m11 = ch * cb + sh * sp * sb;
	m12 = -ch * sb + sh * sp * cb;
	m13 = sh * cp;

	m21 = sb * cp;
	m22 = cb * cp;
	m23 = -sp;

	m31 = -sh * cb + ch * sp * sb;
	m32 = sb * sh + ch * sp * cb;
	m33 = ch * cp;

}
