#include "stylice.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool isWhitespace(char c) {
	return (c == '\t' || c == '\0');
}

static bool isNewline(char c) {
	return c == '\n';
}

void table_AddRow(table *self, const char *format) {
	int column_len = 0, columns = 0;
	for (size_t idx = 0; idx < strlen(format); ++ idx) {
		if (!isWhitespace(format[idx]) && !isNewline(format[idx])) {
			++ column_len;
			continue;
		}
		if (column_len > self->columns_len[columns]) {
			self->columns_len[columns] = column_len;
		}
		++ columns;
		column_len = 0;
	}
	strcat(self->columns, format);
}

void table_Print(table *self) {
	int spaces = 0, column_len = 0, columns = 0;
	for (size_t idx = 0; idx < strlen(self->columns); ++ idx) {
		// If not a whitespace or new line, print the character
		if (!isWhitespace(self->columns[idx]) && !isNewline(self->columns[idx])) {
			printf("%c", self->columns[idx]);
			++ column_len;
			continue;
		}
		// If new line, reset column (and move onto the next row)
		if (isNewline(self->columns[idx])) {
			printf("\n");
			columns = column_len = 0;
			continue;
		}
		// Whitespace detected, do the padding as required
		spaces = (self->columns_len[columns] - column_len);
		do {
			printf("%c", self->delimeter);
		}
		while (spaces -- > 0);
		++ columns;
		column_len = 0;
	}
	printf("\n");
}

void table_init(table *self, const char delimeter) {
	// Reset the table
	static const table emptyTable;
	*self = emptyTable;
	self->delimeter = delimeter;
}