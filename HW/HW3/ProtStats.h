#ifndef PROTSTATS_H
#define PROTSTATS_H

typedef enum { Hydrophobic, Polar, Charged } aa_type;


typedef struct {
	char* name;
	int length;
	float freq_aa[3];
}ProtStats;

int num_prots(const char*);

ProtStats * ProtStatsCreate(char*, char*);

void ProtStatsInit(char* , char* , ProtStats*);

void ProtStatsCopy(ProtStats* , ProtStats* );

void ProtStatsSwap(ProtStats* , ProtStats* );

ProtStats* file_fasta_read(char* , unsigned int* );

aa_type find_type(char );
#endif