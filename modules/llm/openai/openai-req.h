
#ifndef OPENAI_REQ
#define OPENAI_REQ
#include <string>
using namespace std;

//curl https://api.openai.com/v1/embeddings \
//  -H "Content-Type: application/json" \
//  -H "Authorization: Bearer $OPENAI_API_KEY" \
//  -d '{
//    "input": "Your text string goes here",
//    "model": "text-embedding-3-small"
//  }'
struct OpenAIReq {
    vector<string> input;
    string model;
};

#endif  // OPENAI_REQ