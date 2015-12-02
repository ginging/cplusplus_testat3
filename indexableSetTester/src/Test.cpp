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



void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testIndexSetFrontWithInt));
	s.push_back(CUTE(testSetAtWithInt));
	s.push_back(CUTE(testIndexSetBackWithInt));
	s.push_back(CUTE(testBracketOperatorFrontWithInt));
	s.push_back(CUTE(testBracketOperatorWithInt));
	s.push_back(CUTE(testBracketOperatorBackWithInt));
	s.push_back(CUTE(testNegativeBracketToPositiveIndex));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



