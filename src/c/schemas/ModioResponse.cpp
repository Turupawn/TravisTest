#include "c/schemas/ModioResponse.h"

extern "C"
{
  void modioInitResponse(ModioResponse* response, json response_json)
  {
    response->code = 0;

    response->result_count = 0;
    if(modio::hasKey(response_json,"result_count"))
    {
      response->result_count = response_json["result_count"];
    }

    response->result_limit = 0;
    if(modio::hasKey(response_json,"result_limit"))
    {
      response->result_limit = response_json["result_limit"];
    }

    response->result_offset = -1;
    if(modio::hasKey(response_json,"result_offset"))
    {
      response->result_offset = response_json["result_offset"];
    }

    json error_json;
    if(modio::hasKey(response_json, "error"))
    {
      error_json = response_json["error"];
    }
    modioInitError(&(response->error), error_json);
  }

  void modioFreeResponse(ModioResponse* response)
  {
    if(response)
    {
      modioFreeError(&(response->error));
    }
  }
}
