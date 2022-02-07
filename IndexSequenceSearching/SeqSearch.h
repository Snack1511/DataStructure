#ifndef _SEQUENCESEARCHING_
typedef struct IndexTableType IndexTable;
struct IndexTableType {
	int PosValue;
	int KeyIdx;
};

int InOrderedSeqSearch(int Arr[], int MaxLength, int idx);
int OrderedSeqSearch(int Arr[], int MaxLength, int idx);
int IndexOrderedSeqSearch(int Arr[], IndexTable tTable[], int MaxLength, int MaxTableLength, int idx);
#endif