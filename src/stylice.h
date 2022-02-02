#ifndef __STYLICE_H__
#define __STYLICE_H__

#include <stdbool.h>

enum tableStyle {
	styleDefault = 0,
	styleCompact = 1,
	styleMax
};

typedef struct tableData {
	bool Header;
	int ColumnsLen[16];
	int ColumnsCount;
	int RowsCount;
	enum tableStyle Style;
	char Rows[2048];
} table;

bool table_Init(table *self, enum tableStyle style, bool header);
void table_AddRow(table *self, const char *format);
void table_Print(table *self);
int  table_GetRowCount(table *self);
int  table_GetColumnCount(table *self);

#endif