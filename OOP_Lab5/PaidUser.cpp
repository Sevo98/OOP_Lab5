#include "PaidUser.h"

void PaidUser::SetPosts(Post* posts, int postsCount)
{
	if (postsCount < 0) 
	{ 
		throw exception("Posts count must be more than 0"); 
	}  
	_posts = posts;  
	_postsCount = postsCount;
}

//User* PaidUser::Login(User** users, int usersCount, string enteredLogin, string enteredPassword)
//{
//
//	return nullptr;
//}

void PaidUser::GetPosts()
{
	cout << "Title: "<< _posts->GetTitle() << endl;
	cout << _posts->GetText() << endl;
}

int PaidUser::GetPostsCount()
{
	return _postsCount;
}

PaidUser::PaidUser(int id, string login, string password, Post* posts, int postsCount) :User(id, login, password)
{
	SetPosts(posts, postsCount);
}

PaidUser::PaidUser(int id, string login, string password) : PaidUser(id, login, password, nullptr, 0)
{
}