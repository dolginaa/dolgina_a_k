#include <bitset/bitset.h>
#include <iostream>
#include<algorithm>
#include <sstream>
#include<string>


Bitset::Bitset(const std::string& data) {
	size_ = data.size();
	arr.resize(size_ / container_size + 1);
	for (int64_t i = 0; i < data.size(); i++) {
		if (data[i] != '0' && data[i] != '1') {
			throw std::invalid_argument("Bitset can get only '1' or '0'");
		}
		arr[(size_ - i - 1) / container_size] |= ((data[i] - '0') << ((size_ - i - 1) % container_size));
	}
	set_masks();
}


Bitset::BitHolder::BitHolder(Bitset* str1, const int64_t pos)
{
	Bitset* str(str1);
	box = pos/str->container_size;
	bit = pos % str->container_size;
}

Bitset::BitHolder Bitset::BitHolder::operator=(const bool rhs)
{
	if (rhs) {
		str->arr[box] |= rhs << (bit);
	}
	else {
		str->arr[box] &= rhs << (bit);
	}
	return *this;
}

Bitset::BitHolder Bitset::BitHolder::operator=(const Bitset::BitHolder& rhs)
{
	if (rhs.str->arr[rhs.box] & rhs.str->masks[rhs.bit])
	{
		str->arr[box] |= str->masks[bit];
	}
	else
	{
		str->arr[box] &= ~(str->masks[bit]);
	}
}

Bitset::BitHolder::operator bool() const
{
	return bool((str->arr[box]) & (str->masks[bit]));
}


Bitset::Bitset(const Bitset& copy)
{
	size_ = copy.size_;
	arr.resize(size_ / container_size + 1);
	for (int i = 0; i < (size_/container_size); ++i)
	{
		arr[i] = copy.arr[i];
	}
	set_masks();
}

Bitset::Bitset(const int64_t size1, const bool filler)
{
	if (size1 < 0)
	{
		throw std::invalid_argument("Bitset error: Bitset size can not be negative");
	}
	size_ = size1;
	arr.resize(size / container_size + 1);
	for (int i = 0;i < size1;++i)
	{
		if (filler)
		{
			arr[i/container_size] |= 1 << (i % container_size);
		}
		else
			arr[i/container_size] = 0;
	}
	set_masks();
}


Bitset& Bitset::operator=(const Bitset& rhs)
{
	size_ = rhs.size_;
	arr.resize(rhs.arr.size());
	for (int i = 0;i < rhs.arr.size();i++)
		arr[i] = rhs.arr[i];
	set_masks();
	return *this;
}

Bitset& Bitset::operator|=(const Bitset& rhs)
{
	if (rhs.size_ != size_)
		throw std::invalid_argument("Bitset error: sizes of operands do not match");
	for (int i = 0;i < arr.size();i++)
	{
		if (arr[i] != rhs.arr[i])
			arr[i] = 1;
	}
	return *this;
}

Bitset& Bitset::operator^=(const Bitset& rhs)
{
	if(rhs.size_!=size_)
		throw std::invalid_argument("Bitset error: sizes of operands do not match");
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != rhs.arr[i])
			arr[i] = 1;
		else arr[i] = 0;
	}
	return *this;
}

Bitset& Bitset::operator&=(const Bitset& rhs)
{
	if(rhs.size_ != size_)
		throw std::invalid_argument("Bitset error: sizes of operands do not match");
	for (int i = 0;i < arr.size();i++)
	{
		if ((arr[i] != rhs.arr[i]) || (arr[i] == 0 && rhs.arr[i] == 0))
			arr[i] = 0;
	}
	return *this;
}

Bitset& Bitset::operator~() const
{
	Bitset copy = Bitset(*this);
	for (int i = 0;i < copy.size_;i++)
		copy[i] = !(copy[i]);
	return copy;
}

Bitset& Bitset::operator<<=(const int64_t rhs)
{
	if (rhs < 0)
		throw std::invalid_argument("Bitset error : bitsize shift by negative count is undefined");
	if (rhs > size_)
	{
		fill(0);
		return *this;
	}
	for (int64_t i = size_-1; i >= rhs;i--)
		(*this)[i] = (*this)[i - 1];
	for (int64_t i = 0; i < rhs; i++)
		(*this)[i] = 0;
	return *this;
}

Bitset& Bitset::operator>>=(const int64_t rhs)
{
	if (rhs < 0)
		throw std::invalid_argument("Bitset error : bitsize shift by negative count is undefined");
	if (rhs > size_)
	{
		fill(0);
		return *this;
	}
	for (int64_t i = 0; i < rhs; i++)
		(*this)[i] = (*this)[i+1];
	for (int64_t i = size_ - 1; i >= rhs;i--)
		(*this)[i] = 0;
	return *this;
}


bool Bitset::operator==(const Bitset& rhs) const
{
	if (size_ != rhs.size_)
		return false;
		for (int64_t i = 0; i < size_; i++)
		{
			if (arr[i] != rhs.arr[i])
				return false;
		}
	return true;
}

bool Bitset::operator!=(const Bitset& rhs) const
{
	return !(operator==(rhs));
}


bool Bitset::operator[](const int64_t pos) const
{
	if(pos<0 || pos>=size_)
		throw std::invalid_argument("Bitset error: index out of range");
	return bool(arr[pos / container_size] & masks[pos % container_size]);
}

Bitset::BitHolder Bitset::operator[](const int64_t pos)
{
	if(pos<0 || pos>=size_)
		throw std::invalid_argument("Bitset error: index out of range");
	return Bitset::BitHolder(this, pos);
}

void Bitset::fill(const bool filler) {
	if (filler)
		for (int i = 0; i < size_; i++)
			arr[i / container_size] |= 1 << ((i) % container_size);
	else
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = 0;
		}
}
void Bitset::set_masks()
{
	masks.resize(container_size);
	container_type mask = 1;
	for (int i = 0;i < masks.size(); i++)
	{
		masks[i] = mask;
		mask <<= 1;
	}
}
void Bitset::resize(const int64_t size1, const bool filler)
{
	int64_t old = this->size_;
	if (size_ > size1)
		size_ = size1;
	if (size1 < old)
	{
		int64_t diff;
		if ((old - size1) > container_size)
			diff = container_size;
		else diff = old - size1;
		for (int64_t i = size1; i < diff; i++) {
			(*this)[i] = filler;
		}
		arr.resize(size1 / container_size + 1);
		size_ = size1;
	}
	else {
		arr.resize(size1 / container_size + 1);
		if (filler) {
			for (int64_t i = old; i < size1; i++) {
				(*this)[i] = filler;
			}
		}
	}
}

std::ostream& Bitset::WriteTo(std::ostream& ostream) const
{
	for (int64_t i = size_ - 1; i >= 0; i--) {
		ostream << (*this)[i];
	}
	return ostream;
}

std::istream& Bitset::ReadFrom(std::istream& istream) const
{
	std::string data = "";
	while (istream.peek() == '0' || istream.peek() == '1') {
		data.push_back(istream.get());
	}
	if (istream.good() || istream.eof()) {
		if (data == "")
			istream.setstate(std::ios::failbit);
		else
			(*this) = Bitset(data);
	}
	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Bitset& data)
{
	right.WriteTo(ostream);
	return ostream;
}

std::istream& operator>>(std::istream& istream, Bitset& data)
{
	right.ReadFrom(istream);
	return istream;
}
Bitset operator>>(const Bitset& lhs, const int64_t rhs)
{
	return (lhs >>= rhs);
}

Bitset operator<<(const Bitset& lhs, const int64_t rhs)
{
	return (lhs <<= rhs);
}

Bitset operator&(const Bitset& lhs, const Bitset& rhs)
{
	return(lhs &= rhs);
}

Bitset operator|(const Bitset& lhs, const Bitset& rhs)
{
	return(lhs |= rhs);
}

Bitset operator^(const Bitset& lhs, const Bitset& rhs)
{
	return(lhs ^= rhs);
}