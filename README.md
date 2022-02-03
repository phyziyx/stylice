# styliCe

StyliCe:  A C library for creating stylised tables in Console

## Features

- Two formatting styles (Default and Compact)
- Header support

## Example

```c
printf("\nDefault Style: Header\n");
if (table_Init(&instance, styleDefault, true) == false) {
    table_AddRow(&instance, "ID\tLocation\tPopulation\tTest");
    table_AddRow(&instance, "01\tKarachi, PK\t15M\tYes");
    table_AddRow(&instance, "02\tLondon, UK\t9M\tYes");
    table_AddRow(&instance, "03\tLos Angeles, US\t4M\tYes");
    table_AddRow(&instance, "04\tBerlin, DE\t3.6M\tNo");
    table_AddRow(&instance, "05\tToronto, CA\t3M\tYes");
    table_Print(&instance);
    printf("Rows: %d - Columns: %d\n", table_GetRowCount(&instance), table_GetColumnCount(&instance));
}
```

![Example](example/example.gif)

### How to build

```bash
cd .\example\
gcc -I..\src\ example.c -o example.exe ..\src\stylice.c
```

## License

MIT
