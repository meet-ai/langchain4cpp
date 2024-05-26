#ifndef OPENAI_RESP
#define OPENAI_RESP
#include <string>

#include "llm/common.h"
using namespace std;
//{
//"object" : "list",
//           "data" : [ {
//      "object": "embedding",
//      "index": 0,
//      "embedding": [
//        -0.006929283495992422,
//        -0.005336422007530928,
//        ... (omitted for spacing)
//        -4.547132266452536e-05,
//        -0.024047505110502243
//      ],
//           } ],
//                    "model" : "text-embedding-3-small",
//                              "usage" : {
//    "prompt_tokens" : 5, "total_tokens" : 5
//}
//}

struct TextEmbedding {
    string object;
    int64_t index;
    vector<float> embedding;
};
struct OpenAIResp {
    string object;
    vector<TextEmbedding> data;
    string model;
    OpenAIUsage usage;
};

#endif
