#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace v1
{
class user : public drogon::HttpController<user>
{
public:
  METHOD_LIST_BEGIN
  //use METHOD_ADD to add your custom processing function here;
  //METHOD_ADD(user::get,"/{2}/{1}",Get);//path is /v1/user/{arg2}/{arg1}
  //METHOD_ADD(user::your_method_name,"/{1}/{2}/list",Get);//path is /v1/user/{arg1}/{arg2}/list
  //ADD_METHOD_TO(user::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
  METHOD_ADD(User::GetProfile, "/profile/{1}", Get);
  METHOD_ADD(User::GetOwnProfile, "/profile", Get);
  METHOD_ADD(User::Update, "/", Patch);
  METHOD_ADD(User::CheckExistenceOrCreate, "/", Post);

  METHOD_LIST_END
  // your declaration of processing function maybe like this:
  // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
  // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;

  void GetProfile(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,std::string &&iduser);
  void GetOwnProfile(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
  void Update(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
  void CheckExistenceOrCreate(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);

};
} // namespace v1
