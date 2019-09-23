#include "gifexporter.h"
#include <QImage>
#include "spritesheet.h"
#include "frame.h"
#include <vector>

GifExporter::GifExporter(SpriteSheet * spritesheet, const char * file_name)
{

    GifWriter * gif_writer = new GifWriter();
    unsigned int height = static_cast<unsigned int>(spritesheet->height);
    unsigned int width = static_cast<unsigned int>(spritesheet->width);

    GifBegin(gif_writer, file_name, height, width, 30, 8, false);

    std::vector<Frame*> frames = spritesheet->get_all_frames_as_a_vector();

    int frames_count = static_cast<int>(frames.size());

    for (int i = 0; i < frames_count; i++)
    {
        QImage qimage = frames[static_cast<unsigned long>(i)]->image;


        uint8_t *image = new uint8_t[(height * width) * 4];
        int pixelPos = 0;
        for (int j = 0; j < spritesheet->height; j++)
        {
             for (int k = 0; k < spritesheet->width; k++)
             {
                 QColor color = qimage.pixelColor(k, j);
                 image[pixelPos] = static_cast<uint8_t>(color.red());
                 image[++pixelPos] = static_cast<uint8_t>(color.green());
                 image[++pixelPos] = static_cast<uint8_t>(color.blue());
                 image[++pixelPos] = static_cast<uint8_t>(color.alpha());
                 pixelPos++;
             }
        }

    GifWriteFrame(gif_writer, image, height, width, 30, 8, false);

    delete[] image;

    }

    GifEnd(gif_writer);
}
