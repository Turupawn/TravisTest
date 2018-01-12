#include "modio_c.h"

void onModsGet(void* object, ModioResponse response, ModioMod* mods, u32 mods_size)
{
  bool* wait = object;
  printf("On mod get response: %i\n",response.code);
  if(response.code == 200)
  {
    printf("Listing mod\n");
    printf("============\n");
    for(u32 i=0; i<mods_size; i++)
    {
      printf("Mod[%i]\n",i);
      printf("Id:\t%i\n",mods[i].id);
      printf("Name:\t%s\n",mods[i].name);
    }

    // Additionally, we can access pagination data to ease future browsing queries
    printf("\nPagination:\n");
    printf("Result count: %i\n",response.result_count);
    printf("Result limit: %i\n",response.result_limit);
    printf("Result Offset: %i\n",response.result_offset);
  }
  *wait = false;
}

int main(void)
{
  modioInit(7, (char*)"e91c01b8882f4affeddd56c96111977b");

  bool wait = true;

  // Before requesting mods, let's define the query filters
  ModioFilterCreator filter;
  modioInitFilter(&filter);
  modioSetFilterLimit(&filter,3);

  printf("Getting mods...\n");

  // Now we finished setting up the filters we are ready to request the mods
  modioGetMods(&wait,filter, &onModsGet);

  while(wait)
  {
    modioProcess();
  }

  modioShutdown();

  printf("Process finished\n");

  return 0;
}
