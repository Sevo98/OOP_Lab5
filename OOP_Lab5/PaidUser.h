#pragma once
#include <iostream>
#include <string>
#include "Post.h"
#include "User.h"
using namespace std;

class PaidUser : public User
{ 
	Post* _posts;  
	int _postsCount;

public:  
	void SetPosts(Post* posts, int postsCount);

	void GetPosts();  
	int GetPostsCount();
	  
	PaidUser(int id, string login, string password, Post* posts, int postsCount);  
	PaidUser(int id, string login, string password);
};

