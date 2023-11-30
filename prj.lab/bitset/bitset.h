#pragma once
#ifndef BITSET
#define BITSET

#include<vector>
#include <iosfwd>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <initializer_list>

class Bitset {
public:
	typedef uint8_t container_type;
	//BitHolder
	class BitHolder {
	public:
		friend class Bitset;
		BitHolder() {};
		BitHolder operator=(const BitHolder& rhs);
		BitHolder operator=(const bool rhs);
		~BitHolder() = default;
		operator bool() const;
	private:
		uint64_t box = 0, bit = 0;
		Bitset* str = nullptr;
		BitHolder(Bitset* str1, const int64_t pos);
	};
	//Constructors
	explicit Bitset(int64_t size = 0, const bool filler = false);
	Bitset(const Bitset& copy);
	Bitset(const std::string& data);

	//Сокращенные операции
	Bitset& operator=(const Bitset& rhs);
	Bitset& operator&=(const Bitset& rhs);
	Bitset& operator|=(const Bitset& rhs);
	Bitset& operator^=(const Bitset& rhs);
	Bitset& operator<<=(const int64_t rhs);
	Bitset& operator>>=(const int64_t rhs);
	Bitset& operator~() const;
	//Операции сравнения
	bool operator==(const Bitset& rhs) const;
	bool operator!=(const Bitset& rhs) const;

	bool operator[](const int64_t pos) const;
	BitHolder operator[](const int64_t pos);
	//методы
	uint64_t size()
	{
		return size_;
	}
	void fill(const bool filler);
	void resize(const int64_t size, const bool filler = false);

	~Bitset() = default;
	std::ostream& WriteTo(std::ostream& ostream) const;
	std::istream& ReadFrom(std::istream& istream) const;

private:
	int64_t size_ = 0;
	uint8_t container_size = (sizeof(uint8_t) * 8);
	std::vector<container_type> masks;
	std::vector<container_type> arr;
	void set_masks();
};
Bitset operator>>(const Bitset& lhs, const int64_t rhs);
Bitset operator<<(const Bitset& lhs, const int64_t rhs);
Bitset operator&(const Bitset& lhs, const Bitset& rhs);
Bitset operator|(const Bitset& lhs, const Bitset& rhs);
Bitset operator^(const Bitset& lhs, const Bitset& rhs);
std::ostream& operator<<(std::ostream& ostream, const Bitset& data);
std::istream& operator>>(std::istream& istream, Bitset& data);
#endif 