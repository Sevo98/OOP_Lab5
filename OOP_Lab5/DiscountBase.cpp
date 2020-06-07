#include "DiscountBase.h"

void DiscountBase::SetCategory(CategoryType categoty)
{
	_category = categoty;
}

CategoryType DiscountBase::GetCategory()
{
	return _category;
}

DiscountBase::DiscountBase(CategoryType category)
{
	SetCategory(category);
}
