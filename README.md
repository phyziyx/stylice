# styliCe

StyliCe:  A C library for creating stylised tables in Console

## Features

- Two formatting styles (Default and Compact)
- Header support

## Roadmap

- [x] Add formatting styles
- [ ] Variable string length support
- [ ] Code optimisations, if any

## Example

```c
printf("\nDefault Style: Header\n");
if (table_Init(&instance, styleDefault, true) == false) {
    table_AddRow(&instance, "ID\tLocation\tPopulation\tTest\n");
    table_AddRow(&instance, "01\tKarachi, PK\t15M\tYes\n");
    table_AddRow(&instance, "02\tLondon, UK\t9M\tYes\n");
    table_AddRow(&instance, "03\tLos Angeles, US\t4M\tYes\n");
    table_AddRow(&instance, "04\tBerlin, DE\t3.6M\tNo\n");
    table_AddRow(&instance, "05\tToronto, CA\t3M\tYes\n");
    table_Print(&instance);
}
```

![Example](example/example.gif)

## License

MIT
