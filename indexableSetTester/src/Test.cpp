#include <vector>
#include <algorithm>
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "indexableSet.h"

struct CaselessComparator {
	bool operator() (const std::string &str1, const std::string &str2) const {
		return std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char l, char r){
			return std::tolower(l) < std::tolower(r);
		});
	}
};

void testDefaultConstructor() {
	IndexableSet<int> indexSet{};
	indexSet.insert(1);
	ASSERT_EQUAL(1, indexSet[0] );
}
void testRangeConstructor() {
	std::vector<int> myInts = {1, 2, 3, 4, 5};
	IndexableSet<int> indexSet(myInts.begin() , myInts.end());
	ASSERT_EQUAL(3, indexSet[2]);
}
void testCopyConstructor() {
	IndexableSet<int> indexSet {1, 2, 3, 4, 5};
	IndexableSet<int> copiedIndexSet(indexSet);
	ASSERT_EQUAL(3, indexSet[2]);
}
void testMoveConstructor() {
	IndexableSet<int> indexSet {1, 2, 3, 4, 5};
	IndexableSet<int> moveIndexSet(std::move(indexSet));
	ASSERT_EQUAL(3, moveIndexSet[2]);
}

void testCaselessCompare() {
	IndexableSet<std::string, CaselessComparator> indexSet {"hallo","Hallo","Test","taste"};
	ASSERT_EQUAL(3, indexSet.size());
}

void testIndexSetFrontWithInt() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet.front();
	ASSERT_EQUAL(1, i);
}
void testIndexSetBackWithInt() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet.back();
	ASSERT_EQUAL(4, i);
}
void testIndexSetSizeAfterCreation() {
	IndexableSet<std::string> indexSet{};
	ASSERT_EQUAL(indexSet.size(), 0);
}
void testSetAtWithInt() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet.at(1);
	ASSERT_EQUAL(2, i);
}
void testBracketOperatorFrontWithInt() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet[0];
	ASSERT_EQUAL(1, i);
}
void testBracketOperatorWithInt() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet[1];
	ASSERT_EQUAL(2, i);
}
void testBracketOperatorBackWithInt() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet[3];
	ASSERT_EQUAL(4, i);
}
void testNegativeBracketToPositiveIndex() {
	IndexableSet<int> indexSet{1,2,3,4};
	int i = indexSet[-1];
	ASSERT_EQUAL(4, i);
}
void testIndexSetFrontWithString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet.front();
	ASSERT_EQUAL("Hallo", compareString);
}
void testIndexSetBackWithString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet.back();
	ASSERT_EQUAL("Tester", compareString);
}
void testSetAtWithString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet.at(1);
	ASSERT_EQUAL("Hoi", compareString);
}
void testBracketOperatorFrontWithString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet[0];
	ASSERT_EQUAL("Hallo", compareString);
}
void testBracketOperatorWithString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet[1];
	ASSERT_EQUAL("Hoi", compareString);
}
void testBracketOperatorBackWithString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet[3];
	ASSERT_EQUAL("Tester", compareString);
}
void testNegativeBracketToPositiveIndexString() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	std::string compareString = indexSet[-1];
	ASSERT_EQUAL("Tester", compareString);
}
void testNegativeIndexBorder() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	ASSERT_THROWS(indexSet[-5], std::out_of_range);
}
void testPositiveIndexBorder() {
	IndexableSet<std::string> indexSet{"Hallo","Hoi","Test","Tester"};
	ASSERT_THROWS(indexSet[4], std::out_of_range);
}
void testNestedIndexableSets() {
	IndexableSet<int> indexSet12{1,2};
	IndexableSet<int> indexSet13{3,4};
	IndexableSet<IndexableSet<int>> indexSet{indexSet12,indexSet13};
	int compareInt = indexSet[-1][0];
	ASSERT_EQUAL(3, compareInt);
}


void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testIndexSetFrontWithInt));
	s.push_back(CUTE(testIndexSetBackWithInt));
	s.push_back(CUTE(testIndexSetSizeAfterCreation));
	s.push_back(CUTE(testSetAtWithInt));
	s.push_back(CUTE(testBracketOperatorFrontWithInt));
	s.push_back(CUTE(testBracketOperatorWithInt));
	s.push_back(CUTE(testBracketOperatorBackWithInt));
	s.push_back(CUTE(testNegativeBracketToPositiveIndex));
	s.push_back(CUTE(testIndexSetFrontWithString));
	s.push_back(CUTE(testIndexSetBackWithString));
	s.push_back(CUTE(testSetAtWithString));
	s.push_back(CUTE(testBracketOperatorFrontWithString));
	s.push_back(CUTE(testBracketOperatorWithString));
	s.push_back(CUTE(testBracketOperatorBackWithString));
	s.push_back(CUTE(testNegativeBracketToPositiveIndexString));
	s.push_back(CUTE(testNegativeIndexBorder));
	s.push_back(CUTE(testPositiveIndexBorder));
	s.push_back(CUTE(testNestedIndexableSets));
	s.push_back(CUTE(testDefaultConstructor));
	s.push_back(CUTE(testRangeConstructor));
	s.push_back(CUTE(testCopyConstructor));
	s.push_back(CUTE(testCaselessCompare));
	s.push_back(CUTE(testMoveConstructor));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}


