#include "draw.h"
//#include "vector.h"
#include "model.h"
#include <vector>
#include "bitmap_image.hpp"
#include "vector.h"


int width = 1000, height = 1000;


draw image(width, height);


model obj("african_head.obj");


int main()
{
	/*obj.show(image, width, height);

	image.save("output.bmp");
	image.zbuffer_img.save_image("zbuffer.bmp");*/

	return 0;
}