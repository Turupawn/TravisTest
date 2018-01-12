#include "c++/schemas/Media.h"

namespace modio
{
  void Media::initialize(ModioMedia modio_media)
  {
    this->youtube.resize(modio_media.youtube_size);
    for(u32 i = 0; i < modio_media.youtube_size; i++)
    {
      this->youtube[i] = modio_media.youtube_array[i];
    }

    this->sketchfab.resize(modio_media.sketchfab_size);
    for(u32 i = 0; i < modio_media.sketchfab_size; i++)
    {
      this->sketchfab[i] = modio_media.sketchfab_array[i];
    }

    this->images.resize(modio_media.images_size);
    for(u32 i = 0; i < modio_media.images_size; i++)
    {
      this->images[i].initialize(modio_media.images_array[i]);
    }
  }
}
