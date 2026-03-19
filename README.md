# my-os
Just tryin` to do something ya know ^*^

# myOS

Моя первая операционная система написанная с нуля.

## Что это

Минимальное ядро ОС которое загружается через GRUB и выводит текст
на экран напрямую через видеопамять VGA. Никаких сторонних библиотек
и никакой операционной системы под капотом — только чистое железо.

## Из чего состоит

- `boot.s` — точка входа на ассемблере. Настраивает стек и передаёт
  управление в ядро. Содержит заголовок Multiboot чтобы GRUB
  мог нас загрузить.
- `kernel.c` — само ядро на C. Выводит текст прямо в видеопамять
  по адресу 0xB8000.
- `linker.ld` — скрипт линковщика. Говорит как склеить всё вместе.

## Как собрать

Нужен кросс-компилятор i686-elf-gcc и GRUB.
```bash
i686-elf-as boot.s -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2
i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
```

## Как запустить
```bash
mkdir -p isodir/boot/grub
cp myos.bin isodir/boot/myos.bin
grub-mkrescue -o myos.iso isodir
qemu-system-i386 -cdrom myos.iso
```

## Что дальше

- [ ] Функция print для вывода текста в любое место экрана
- [ ] Обработка прерываний (IDT)
- [ ] Ввод с клавиатуры
- [ ] Своя командная строка
