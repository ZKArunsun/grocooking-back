#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace v1
{
class comment:public drogon::HttpController<comment>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(comment::get,"/{2}/{1}",Get);//path is /v1/comment/{arg2}/{arg1}
    //METHOD_ADD(comment::your_method_name,"/{1}/{2}/list",Get);//path is /v1/comment/{arg1}/{arg2}/list
    //ADD_METHOD_TO(comment::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
      METHOD_ADD(Comment::Create,"/",Post);
      METHOD_ADD(Comment::Read,"/{1}",Get);
      METHOD_ADD(Comment::Update,"/",Update);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
      void Create(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
      void Read(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,std::string &&idrecipe);
      void Update(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
};
}
