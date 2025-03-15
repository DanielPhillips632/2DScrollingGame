#include "header.h"
#include "ImageTracking.h"

bool ImageTracking::mapCoordinates(double& x, double& y, const SimpleImage& image)
{
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= (image.getWidth() - 0.5)) return false;
	if (y >= (image.getHeight() - 0.5)) return false;

	x -= image.getWidth() / 2;
	y -= image.getHeight() / 2;

	double dAngle = atan(y / (x + 0.0001));
	if (x < 0)
		dAngle += M_PI;
	double hyp = ::sqrt(x * x + y * y);

	double faceAngle = atan2(sourceX - destX, sourceY - destY);

	dAngle += faceAngle;

	x = hyp * ::cos(dAngle);
	y = hyp * ::sin(dAngle);

	x += image.getWidth() / 2;
	y += image.getHeight() / 2;

	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= (image.getWidth() - 0.5)) return false;
	if (y >= (image.getHeight() - 0.5)) return false;

	return true;
}
