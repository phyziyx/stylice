#include "stylice.h"
#include <stdio.h>
#include <string.h>

static bool isWhitespace(char c) {
	return (c == '\t' || c == '\0');
}

static bool isNewline(char c) {
	return c == '\n';
}

static void printSeparator(table *self) {
	int
		idx = 0,
		sum = 0
	;

	idx = sum = self->ColumnsCount + 1;

	while (-- idx != 0) {
		sum += self->ColumnsLen[idx];
	}

	while (sum --) {
		printf("-");
	}
	printf("\n");
}

bool table_Init(table *self, enum tableStyle style, bool header) {
	if (style < styleDefault || style >= styleMax) {
		return true;
	}

	// Reset the table and initialise data
	static const table
		emptyTable
	;

	*self = emptyTable;
	self->Style = style;
	self->Header = header;
	return false;
}

void table_AddRow(table *self, const char *format) {
	int
		columnLen = 0,
		column = 0
	;

	for (size_t idx = 0; idx < strlen(format); ++ idx) {
		// If not a whitespace and newline, increase the column length
		if (!isWhitespace(format[idx]) && !isNewline(format[idx])) {
			++ columnLen;
			continue;
		}

		// If the column length is larger than previous
		if (columnLen > self->ColumnsLen[column]) {
			self->ColumnsLen[column] = columnLen;
		}

		++ column;
		columnLen = 0;
	}

	strcat(self->Rows, format);
	++ self->RowsCount;
	self->ColumnsCount = column;
}

void table_Print(table *self) {
	int
		spaces = 0,
		columnLen = 0,
		column = 0
	;

	bool
		header = self->Header
	;

	if (header && self->Style == styleDefault) {
		printSeparator(self);
	}

	for (size_t idx = 0; idx < strlen(self->Rows); ++ idx) {
		// If not a whitespace or new line, print the character
		if (!isWhitespace(self->Rows[idx]) && !isNewline(self->Rows[idx])) {
			printf("%c", self->Rows[idx]);
			++ columnLen;
			continue;
		}

		// If new line, reset column (and move onto the next row)
		if (isNewline(self->Rows[idx])) {
			printf("\n");
			column = columnLen = 0;

			if (header) {
				printSeparator(self);
				header = false;
			}
			continue;
		}

		// Whitespace detected, do the padding as required
		spaces = (self->ColumnsLen[column] - columnLen);
		do {
			printf(" ");
			++ columnLen;
		}
		while (spaces -- > 0);

		++ column;
		columnLen = 0;
	}

	if (self->Header && self->Style == styleDefault) {
		printSeparator(self);
	}

	printf("\n");
}