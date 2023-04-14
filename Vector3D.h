#pragma once

class Vector3D
{
public:
	double X{ 0.0 };
	double Y{ 0.0 };
	double Z{ 0.0 };

	Vector3D() = default;

	Vector3D(double v)
		: X(v), Y(v), Z(v){
	}

	Vector3D(double x, double y, double z)
		: X(x), Y(y), Z(z){
	}
	void Set(double x, double y, double z) {
		X = x;
		Y = y;
		Z = z;
	}
	Vector3D operator-(const Vector3D& a) const {
		return  Vector3D(X - a.X, Y - a.Y, Z - a.Z);
	}

	bool operator==(const Vector3D& a) const {
		return  X == a.X && Y == a.Y && Z == a.Z ? 1 : 0;
	}

	double DotProduct(const Vector3D& a) {
		return X * a.X + Y * a.Y + Z * a.Z;
	}

};