#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;


struct Product
{
    float length;
    float breadth;
    float height;
};

struct ProductDimensions
{

    vector<Product*> breadthGreaterThan(vector<Product*> items, float breadth)
    {
        vector<Product*> result;
        for(auto& i:items)
            {
                if(i->breadth >= breadth)
                {
                    result.push_back(i);
                }
            }
        return result;
    }

    vector<Product*> lengthGreaterThan(vector<Product*> items, float length)
    {
        vector<Product*> result;
        for(auto& i:items){
            if(i->length >= length)
            {
                result.push_back(i);
            }
        }
        return result;
    }

    vector<Product*> heightGreaterThan(vector<Product*> items, float height)
    {
        vector<Product*> result;
        for(auto& i:items){
            if(i->height >= height)
            {
                result.push_back(i);
            }
        }
        return result;
    }
    //Problem with above code?
    //Write a function 

    vector<Product*> volumeGreaterThan(vector<Product*> items, float length, float breadth, float height)
    {
        vector<Product*> result;
        float volume = length*breadth*height;
        for(auto& i:items){
            float itemVolume = i->length*i->breadth*i->height;
            if(itemVolume>=volume)
                result.push_back(i);
        }
        return result;
    }

};

/*Problem with above code?
Writing new code again and again and defining new functions again and again causes problem at client end.

Better Version of the above code
is to define interfaces and inherit them.

This concept is called Open Closed Principle meaning 

Open to Extension and Closed to Modification

Plsu this type of Programming gives you more freedom to write your own code.

*/

template <typename T> struct Specification
{
    virtual ~Specification() = default;

    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Calculation
{
    virtual vector<T*> greaterThan(vector<T*> items, Specification<T>& s) = 0;
};

struct genericGreaterThan:Calculation<Product>
{
    vector<Product*> greaterThan(vector<Product*> items, Specification<Product> &spec) override
    {
        vector<Product*> result;
        for(auto& i:items){
            if(spec.is_satisfied(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};

struct LengthSpecification:Specification<Product>
{
    Product pr1;
    LengthSpecification(Product p):pr1(p){}

    bool is_satisfied(Product* item) override
    {
        return item->length == pr1.length;
    }
};


struct VolumeSpecification:Specification<Product>
{

    Product pr2;
    VolumeSpecification(Product p):pr2(p){}

    bool is_satisfied(Product* item) override
    {
        float itemVolume = item->length*item->breadth*item->height;
        return itemVolume == pr2.length*pr2.breadth*pr2.height;
    }
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
and SEO Description = VALO exists to identify, create and implement visionary technologies that can sustainably enhance human experience and capabilities.

/*
I2 = SEO
H2 = KEYWORDS
F2 = EMPLOYEEES
IF(CONDITION,IF IS TRUE, IF IS FALSE)
=IF(ISBLANK(H2)," ",H2)&IF(ISBLANK(I2)," "," AND SEO DESCRIPTION = "&I2)&IF(ISBLANK(F2)," "," AND EMPLOYEE COUNT = "&F2)

*/