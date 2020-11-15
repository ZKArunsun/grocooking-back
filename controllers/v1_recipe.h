#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace v1
{
class recipe:public drogon::HttpController<recipe>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(recipe::get,"/{2}/{1}",Get);//path is /v1/recipe/{arg2}/{arg1}
    //METHOD_ADD(recipe::your_method_name,"/{1}/{2}/list",Get);//path is /v1/recipe/{arg1}/{arg2}/list
    //ADD_METHOD_TO(recipe::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
      METHOD_ADD(Recipe::Create,"/",Post);
      METHOD_ADD(Recipe::Read,"/{1}",Get);
      METHOD_ADD(Recipe::Update,"/",Update);
      METHOD_ADD(Recipe::Fetch,"/",Get)
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
  void Create(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
  void Read(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
  void Update(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
  void Fetch(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);

};
}
