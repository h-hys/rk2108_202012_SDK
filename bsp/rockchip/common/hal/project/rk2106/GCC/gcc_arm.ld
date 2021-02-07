/* Linker script to configure memory regions. */
MEMORY
{
	SRAM (rwx) : ORIGIN = 0x03000000, LENGTH = 640K
}

BOOT_ROM_BASE		= 0x03050000;
SYS_DATA_BASE		= 0x03000000;
LOADER_DATA_BASE	= 0x0304A000;
SYS_CODE_BASE		= 0x03050000;
LOADER_CODE_BASE	= 0x03088000;

SECTIONS
{
	/* Module info table */
	.MODULE_INFO 0x21000000 : AT (BOOT_ROM_BASE)
	{
		. = ALIGN(4);
		KEEP(*(_ModuleInfo_))
		. = ALIGN(4);
	}

	.TASK_INF_DATA 0x8a000000 : AT (LOADADDR(.MODULE_INFO) + SIZEOF(.MODULE_INFO))
	{
		. = ALIGN(4);
		KEEP(*(.InitTaskItem))
		. = ALIGN(4);
	}

	.SRC_FILTER_DATA 0x8C000000 : AT (LOADADDR(.TASK_INF_DATA) + SIZEOF(.TASK_INF_DATA))
	{
		. = ALIGN(4);
		KEEP(*(srctable8_44))
		KEEP(*(srctable16_44))
		KEEP(*(srctable32_44))
		KEEP(*(srctable12_44))
		KEEP(*(srctable11_44))
		KEEP(*(srctable48_44))
		. = ALIGN(4);
	}

	/* System section */

	.AP_SYS_CODE SYS_CODE_BASE : AT (LOADADDR(.SRC_FILTER_DATA) + SIZEOF(.SRC_FILTER_DATA))
	{
		__text_start__ = .;
		KEEP(*(.isr_vector))
		KEEP(*(AP_START_CODE))
		*(.text*)
		KEEP(*(SysCode))
		KEEP(*(SysInitCode))
		KEEP(*(*_init))
		KEEP(*(*_shell))
		KEEP(*(*_common))
		KEEP(*(.init))
		KEEP(*(.fini))

		/* .ctors */
		*crtbegin.o(.ctors)
		*crtbegin?.o(.ctors)
		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
		*(SORT(.ctors.*))
		*(.ctors)

		/* .dtors */
		*crtbegin.o(.dtors)
		*crtbegin?.o(.dtors)
		*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
		*(SORT(.dtors.*))
		*(.dtors)

		. = ALIGN(4);
		__rodata_start__ = .;
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		__rodata_end__ = .;

		KEEP(*(.eh_frame*))
		/* All text end */
		__text_end__ = .;
	} > SRAM

	ASSERT(__text_end__ < LOADER_CODE_BASE, " Text region overflowed")

	/DISCARD/ :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	}

	.AP_SYS_DATA SYS_DATA_BASE : AT (LOADADDR(.AP_SYS_CODE) + SIZEOF(.AP_SYS_CODE))
	{
		__data_start__ = .;
		_sdata = .;

		KEEP(*(ap_vect))
		KEEP(*(.DevInfo_Table))
		KEEP(*(SysData))
		*(.data*)
		KEEP(*(SysInitData))
		KEEP(*(*_common_data))
		KEEP(*(*_init_data))
		KEEP(*(*_shell_data))

		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);

		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		KEEP(*(.jcr*))
		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;
		_edata = .;
	} > SRAM

	.AP_SYS_BSS : AT (LOADADDR(.AP_SYS_DATA) + SIZEOF(.AP_SYS_DATA))
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(SysBss)
		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		/* All bss end */
		__bss_end__ = .;
	} > SRAM

	ASSERT(__bss_end__ < LOADER_DATA_BASE, " Data region overflowed")

	.HEAP_STACK (COPY) :
	{
		KEEP(*(HeapStack))
	} > SRAM

	.APP_HEAP_STACK (COPY) :
	{
		__end__ = .;
		end = __end__;
		KEEP(*(AppHeapStack))
		__HeapLimit = .;
	} > SRAM

	.AP_MAIN_STACK (NOLOAD) :
	{
		KEEP(*(APMainStack))
	} > SRAM

	.IDLE_STACK (NOLOAD) :
	{
		KEEP(*(IdleStack))
	} > SRAM
	__StackTop = ORIGIN(SRAM) + LENGTH(SRAM);
	ASSERT(__HeapLimit < SYS_CODE_BASE, " Stack region overflowed")

	PROVIDE(Load$$MODULE_INFO$$Base			= LOADADDR(.MODULE_INFO));
	PROVIDE(Image$$MODULE_INFO$$Base		= ADDR(.MODULE_INFO));

	PROVIDE(Load$$AP_SYS_CODE$$Base			= LOADADDR(.AP_SYS_CODE));
	PROVIDE(Image$$AP_SYS_CODE$$Base		= ADDR(.AP_SYS_CODE));
	PROVIDE(Image$$AP_SYS_CODE$$Length		= SIZEOF(.AP_SYS_CODE));

	PROVIDE(Load$$AP_SYS_DATA$$Base			= LOADADDR(.AP_SYS_DATA));
	PROVIDE(Image$$AP_SYS_DATA$$RW$$Base		= ADDR(.AP_SYS_DATA));
	PROVIDE(Image$$AP_SYS_DATA$$RW$$Length		= SIZEOF(.AP_SYS_DATA));
	PROVIDE(Image$$AP_SYS_DATA$$ZI$$Base		= ADDR(.AP_SYS_BSS));
	PROVIDE(Image$$AP_SYS_DATA$$ZI$$Length		= SIZEOF(.AP_SYS_BSS));

	PROVIDE(Load$$TASK_INF_DATA$$Base		= LOADADDR(.TASK_INF_DATA));
	PROVIDE(Image$$TASK_INF_DATA$$Base		= ADDR(.TASK_INF_DATA));
	PROVIDE(Image$$TASK_INF_DATA$$Length		= SIZEOF(.TASK_INF_DATA));
	PROVIDE(Image$$TASK_INF_DATA$$ZI$$Base		= 0);
	PROVIDE(Image$$TASK_INF_DATA$$ZI$$Length	= 0);

	PROVIDE(Load$$SRC_FILTER_DATA$$Base		= LOADADDR(.SRC_FILTER_DATA));
	PROVIDE(Image$$SRC_FILTER_DATA$$Base		= ADDR(.SRC_FILTER_DATA));
	PROVIDE(Image$$SRC_FILTER_DATA$$Length		= SIZEOF(.SRC_FILTER_DATA));
	PROVIDE(Image$$SRC_FILTER_DATA$$ZI$$Base	= ADDR(.SRC_FILTER_DATA));
	PROVIDE(Image$$SRC_FILTER_DATA$$ZI$$Length	= SIZEOF(.SRC_FILTER_DATA));

	PROVIDE(Image$$APP_HEAP_STACK$$RW$$Base		= ADDR(.APP_HEAP_STACK));
	PROVIDE(Image$$APP_HEAP_STACK$$RW$$Length	= SIZEOF(.APP_HEAP_STACK));
	PROVIDE(Image$$APP_HEAP_STACK$$ZI$$Base		= ADDR(.APP_HEAP_STACK));
	PROVIDE(Image$$APP_HEAP_STACK$$ZI$$Length	= SIZEOF(.APP_HEAP_STACK));

	PROVIDE(Image$$HEAP_STACK$$RW$$Base		= ADDR(.HEAP_STACK));
	PROVIDE(Image$$HEAP_STACK$$RW$$Length		= SIZEOF(.HEAP_STACK));
	PROVIDE(Image$$HEAP_STACK$$ZI$$Base		= ADDR(.HEAP_STACK));
	PROVIDE(Image$$HEAP_STACK$$ZI$$Length		= SIZEOF(.HEAP_STACK));

	PROVIDE(Image$$AP_MAIN_STACK$$RW$$Limit		= ADDR(.AP_MAIN_STACK));
	PROVIDE(Image$$AP_MAIN_STACK$$RW$$Base		= ADDR(.AP_MAIN_STACK));
	PROVIDE(Image$$AP_MAIN_STACK$$RW$$Length	= SIZEOF(.AP_MAIN_STACK));
	PROVIDE(Image$$AP_MAIN_STACK$$ZI$$Limit		= ADDR(.AP_MAIN_STACK));
	PROVIDE(Image$$AP_MAIN_STACK$$ZI$$Base		= ADDR(.AP_MAIN_STACK));
	PROVIDE(Image$$AP_MAIN_STACK$$ZI$$Length	= SIZEOF(.AP_MAIN_STACK));

	PROVIDE(Image$$IDLE_STACK$$RW$$Base		= ADDR(.IDLE_STACK));
	PROVIDE(Image$$IDLE_STACK$$RW$$Length		= SIZEOF(.IDLE_STACK));
	PROVIDE(Image$$IDLE_STACK$$ZI$$Base		= ADDR(.IDLE_STACK));
	PROVIDE(Image$$IDLE_STACK$$ZI$$Length		= SIZEOF(.IDLE_STACK));
}
