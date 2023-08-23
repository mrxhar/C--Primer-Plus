#include <iostream>
#ifndef TEXT2_H_
#define TEXT2_H_

namespace VECTOR {

	class Vector
	{
	public:
		enum Mode
		{
			RECT, POL
		};
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();

		void reset(double n1, double n2, Mode form = RECT);

		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return sqrt(x * x + y * y); }
		double angval() const {
			if (x == 0.0 && y == 0.0)
			{
				return 0;
			}
			else
			{
				return atan2(y, x);
			}
		}

		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& a);

	private:
		double x;
		double y;
		Mode mode;
	};

}


#endif // !TEXT2_H_

