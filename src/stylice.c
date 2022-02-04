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

	// If the style is Windows
	if (self->Style == styleWindows) {
		// Loop for each column
		while (idx != self->ColumnsCount) {
			sum = self->ColumnsLen[idx];

			// Print the dashes of the column length
			while (sum --) {
				printf("-");
			}
			printf("  ");
			// Next iteration
			idx ++;
		}
		printf("\n");

		return;
	}

	idx = sum = self->ColumnsCount;
	sum *= 2;

	while (-- idx) {
		sum += self->ColumnsLen[idx];
	}

	while (sum --) {
		printf("-");
	}
	printf("\n");
}

void table_Empty(table *self) {
	static const table
		emptyTable
	;

	*self = emptyTable;
}

bool table_Init(table *self, enum tableStyle style, bool header) {
	if (style < styleDefault || style >= styleMax) {
		return true;
	}

	table_Empty(self);
	// Initialise the settings
	self->Style = style;
	self->Header = header;
	return false;
}

void table_AddRow(table *self, const char *format) {
	int
		columnLen = 0,
		column = 0
	;

	for (
		size_t idx = 0, max = strlen(format);
		idx <= max;
		++ idx
	) {
		// If not a whitespace and end of the string, increase the column length
		if (!isWhitespace(format[idx]) && idx != max) {
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
	strcat(self->Rows, "\n");
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

	for (
		size_t idx = 0, max = strlen(self->Rows);
		idx < max;
		++ idx
	) {
		// If not a whitespace and new line, print the character
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
		}
		while (spaces -- > 0);
		// One extra space between each column
		printf(" ");

		++ column;
		columnLen = 0;
	}

	if (self->Header && self->Style == styleDefault) {
		printSeparator(self);
	}

	printf("\n");
}

int table_GetRowCount(table *self) {
	return self->RowsCount;
}

int table_GetColumnCount(table *self) {
	return self->ColumnsCount;
}
