#include "Vector.h"

/* Vector2D Class */

Vector2D::Vector2D()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::operator+(Vector2D addv)
{
	return Vector2D(this->x + addv.x, this->y + addv.y);
}

Vector2D Vector2D::operator-(Vector2D subv)
{
	return Vector2D(this->x - subv.x, this->y - subv.y);
}

Vector2D Vector2D::operator*(float cnst)
{
	return Vector2D(this->x * cnst, this->y * cnst);
}

float Vector2D::GetX()
{
	return this->x;
}

float Vector2D::GetY()
{
	return this->y;
}

float Vector2D::Length()
{
	return (sqrt(this->x*this->x + this->y*this->y));
}

/* Vector3D Class */

Vector3D::Vector3D()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D Vector3D::operator+(Vector3D addv)
{
	return Vector3D(this->x + addv.x, this->y + addv.y, this->z + addv.z);
}

Vector3D Vector3D::operator-(Vector3D subv)
{
	return Vector3D(this->x - subv.x, this->y - subv.y, this->z - subv.z);
}

Vector3D Vector3D::operator*(float cnst)
{
	return Vector3D(this->x * cnst, this->y * cnst, this->z * cnst);
}

float Vector3D::GetX()
{
	return this->x;
}

float Vector3D::GetY()
{
	return this->y;
}

float Vector3D::GetZ()
{
	return this->z;
}

float Vector3D::Length()
{
	return (sqrt(this->x*this->x + this->y*this->y + this->z*this->z));
}

void Vector3D::Normalize()
{
	float l = this->Length();
	this->x /= l;
	this->y /= l;
	this->z /= l;
}

float Vector3D::DotProduct(Vector3D vec)
{
	return (this->GetX() * vec.GetX() + this->GetY() * vec.GetY() + this->GetZ() * vec.GetZ());
}

Vector3D Vector3D::CrossProduct(Vector3D vec)
{
	return Vector3D(this->GetY()*vec.GetZ() - this->GetZ()*vec.GetY(), this->GetZ()*vec.GetX() - this->GetX()*vec.GetZ(), this->GetX()*vec.GetY() - this->GetY()*vec.GetX());
}

Vector2D Vector3D::ToVector2D()
{
	return Vector2D(this->x,this->y);
}