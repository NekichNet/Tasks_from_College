#include <iostream>

template <typename Type>
class UniquePtr {
public:
	UniquePtr():data_(nullptr){}
	UniquePtr(Type* data) {
		data_ = new Type*;
		std::memcpy(data_, data, sizeof(data));
		delete data;
	}
	~UniquePtr() { if (data_) delete data_; }
	
	Type& operator*() { return *data_; }
	Type* operator->() { return data_; }

	UniquePtr(const UniquePtr& p) = delete;
	UniquePtr(UniquePtr&& p) = delete;
private:
	Type* data_;
};

int main() {
	std::string a = "654gdf";
	UniquePtr<std::string> ptr = &a;

	ptr->at(4);

	return 0;
}