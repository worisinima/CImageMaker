#pragma once

class FColor
{
public:

	FColor() :
		R(0),
		G(0),
		B(0)
	{}

	FColor(int r, int g, int b) :
		R(r),
		G(g),
		B(b)
	{}

	~FColor() {}

	int R;
	int G;
	int B;
};

class FLinerColor
{

public:

	FLinerColor(float r, float g, float b) :
		R(r),
		G(g),
		B(b)
	{}

	FLinerColor() :
		R(0),
		G(0),
		B(0)
	{}

	~FLinerColor() {}

	FColor LinerColorToFColor() const
	{
		FColor retcol;

		retcol.R = (int)(R * 255);
		retcol.G = (int)(G * 255);
		retcol.B = (int)(B * 255);

		return retcol;
	}

	float R;
	float G;
	float B;
};

class FVector
{
public:

	FVector(float x, float y, float z) :
		X(x),
		Y(y),
		Z(z)
	{}

	FVector() {}
	~FVector() {}

	FVector operator+ (const FVector& Ref)
	{
		FVector ret;
		ret.X = this->X + Ref.X;
		ret.Y = this->Y + Ref.Y;
		ret.Z = this->Z + Ref.Z;

		return ret;
	}

	FVector operator- (const FVector& Ref)
	{
		FVector ret;
		ret.X = this->X - Ref.X;
		ret.Y = this->Y - Ref.Y;
		ret.Z = this->Z - Ref.Z;

		return ret;
	}

	FVector operator* (const FVector& Ref)
	{
		FVector ret;
		ret.X = this->X * Ref.X;
		ret.Y = this->Y * Ref.Y;
		ret.Z = this->Z * Ref.Z;

		return ret;
	}

	FVector operator/ (const FVector& Ref)
	{
		FVector ret;
		ret.X = this->X / Ref.X;
		ret.Y = this->Y / Ref.Y;
		ret.Z = this->Z / Ref.Z;

		return ret;
	}

	void operator= (const FVector& Ref)
	{
		this->X = Ref.X;
		this->Y = Ref.Y;
		this->X = Ref.Z;
	}

	float X;
	float Y;
	float Z;
};

class FVector2D
{
public:

	FVector2D(float x, float y) :
		X(x),
		Y(y)
	{}

	FVector2D() {}
	~FVector2D() {}


	FVector2D operator+ (const FVector2D& Ref)
	{
		FVector2D ret;
		ret.X = this->X + Ref.X;
		ret.Y = this->Y + Ref.Y;

		return ret;
	}

	FVector2D operator- (const FVector2D& Ref)
	{
		FVector2D ret;
		ret.X = this->X - Ref.X;
		ret.Y = this->Y - Ref.Y;

		return ret;
	}

	FVector2D operator* (const FVector2D& Ref)
	{
		FVector2D ret;
		ret.X = this->X * Ref.X;
		ret.Y = this->Y * Ref.Y;

		return ret;
	}

	FVector2D operator/ (const FVector2D& Ref)
	{
		FVector2D ret;
		ret.X = this->X / Ref.X;
		ret.Y = this->Y / Ref.Y;

		return ret;
	}

	void operator= (const FVector2D& Ref)
	{
		this->X = Ref.X;
		this->Y = Ref.Y;
	}

	float X;
	float Y;
};

