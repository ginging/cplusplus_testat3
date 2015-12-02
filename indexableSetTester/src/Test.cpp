#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "indexableSet.h"

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
	IndexableSet<IndexableSet> indexSet{IndexableSet<int> indexSet12{1,2}, IndexableSet<int> indexSet13{3,4}};
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
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
