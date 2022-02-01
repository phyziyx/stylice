#ifndef __STYLICE_H__
#define __STYLICE_H__

typedef struct tableData {
	int columns_len[16];
	char delimeter;
	char columns[2048];
} table;

void table_init(table *self, const char delimeter);
void table_AddRow(table *self, const char *format);
void table_Print(table *self);

#endif