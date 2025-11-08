# <span style="background-color:chocolate">ОБЩИЕ ЗАМЕТКИ</span><br>
<span style="background-color: green">Можно скомпилиривать как при помощи gcc, так и cc - второй создаст файл a.out. Или, как у gcc, можно добавить флаг -o и скомпилить файл с нужным именем.</span>

C имеет две потенциальные <span style="color:orange">среды выполнения:
1. <span style="color:orange">минимальную - freestanding</span>
2. <span style="color:orange">полноценную - hosted</span><br>

<span style="background-color:red; color:black">---Минимальная среда выполнения---</span>
1. Может существовать вне ОС
2. Используется в создании встраиваемых систем
3. Предоставляет минимальный набор библиотечных функций, а объявление точки входа отличается в разных реализациях

Программы на C состоят из <span style="color:orange">процедур (функций, методов)</span>, которые:
1. имеют определённый тип и могут возвращять определённые значения (тип функции = тип возвращаемого значения)
2. могут принимать аргументы

# <span style = "background-color:chocolate">ВВЕДЕНИЕ В C</span>

## <span style="background-color:green">Директивы препроцессора</span><br>
<span style="color:violet">#include</span> - ведет себя так, будто вместо нее подставляется содержимое указанного файла. По сути, подключает нужный файл.

## <span style="background-color:green">Стандартные библиотеки</span><br>

<span style="color:violet">stdio.h</span> - I/O - содержит методы ввода/вывода.<br>
<span style="color:violet">stdlib.h</span> - функции общего назначения.<br>

## <span style="background-color:green">Входная точка программы</span>

<span style="color:violet">int main()</span>  - входная точка программы<br>
<span style="color:violet">(void)</span> - даёт понять, что main <span style="color:orange">ничего не принимает.</span>

Предназанчение возаращемого функцией main значения - <span style="color:orange">указать, как завершилась программа - успешно или нет</span>

### <span style="background-color:red; color:black">---Как происходит вход/выход в/из программы:---</span><br>

#### ВХОД 
main - входная точка, выполняемая при запуске программы
выполняется функция main в серверной среде, после запуска из командной строки или другой программы

#### ВЫХОД 
return (0 или 1, или макросы, представляющие эти значения) - выход из программы -- среда исполнения получает возврат из функции main, по которому может проверить состояние проги и определить, насколько успешен был вызов.

#### ЗАМЕЧАНИЯ 
return __value__ в main = exit(__value__) 

## <span style="background-color:green">ФОРМАТИРОВАННЫЙ ВЫВОД</span><br>

<span style="color:violet">printf</span> (или ее вариации) - функция, для форматированного вывода. Принимает строку, которая описывет формат вывода и произвольное количество аргументов, представляющих значения для вывода. Сама же возвращает количество выведенных символов, а при возникновении ошибки — отрицательное значение 
> <span style="color:red">АЛАРМ! ОПАСНОСТЬ! Никогда пользовательские данные не должны быть первым аргументом функции (т.е. как строку формата), т.к это может привести к утечкам памяти или инфы. Например:

```c
int main() {
    char buffer[100];
    
    // Симуляция ввода злоумышленника
    char *malicious_input = "%08x %08x %08x %08x";
    
    printf("=== УЯЗВИМЫЙ ВЫЗОВ ===\n");
    printf(malicious_input);  // ОПАСНО!
    printf("\n");
    
    printf("=== БЕЗОПАСНЫЙ ВЫЗОВ ===\n");
    printf("%s", malicious_input);  // БЕЗОПАСНО
    printf("\n");
    
    return 0;
}
```

>Вывод уязвимой версии может показать:
0041a2c0 00000001 7ffd42a8 0041a2c0
(это служебные данные из стека - УТЕЧКА ИНФОРМАЦИИ!)
</span>

### <span style="background-color:red; color:black">__Спецификаторы формата__</span> (не все)
1. <span style="color:violet">%s</span> - спецификатор формата, позволяющий вывести очередной аргумент - <span style="color:orange">строку</span>
2. <span style="color:violet">%d</span> - спецификатор формата, позволяющий вывести очередной аргумент - <span style="color:orange">целое число</span>
3. <span style="color:violet">%f</span> - спецификатор формата, позволяющий вывести очередной аргумент - <span style="color:orange">число с плавающей точкой</span>
4. <span style="color:violet">%c</span> - спецификатор формата, позволяющий вывести очередной аргумент - <span style="color:orange">символ</span>
5. <span style="color:violet">%x</span> - спецификатор формата, позволяющий вывести очередной аргумент - <span style="color:orange">шестнадцатиричное число</span>

### <span style="background-color:red; color:black">Алфавитные управляющие последовательности</span>
Необходимы для вывода неотображаемых символов. Список последовательностей:
1. <span style="color:violet">\n</span> - перевод строки

## <span style="background-color:green">БИБЛИОТЕЧНЫЕ МЕТОДЫ И МАКРОСЫ</span>

<span style="color:violet">int puts(const char*)</span>
1. записывает полученный аргумент в поток <span style="color:orange">stdout (консоль или терминал)</span>, добавляя к выводу '\n'
2. если во время вывода возникла ошибка, возвращается макрос EOF (представляющий отрицательное число) - иначе целое неотрицательное значение
    
<span style="color:violet">**EXIT_SUCCESS**</span>
1. макрос, зачастую имеет такое определение - #define EXIT_SUCCESS 0

<span style="color:violet">EOF</span>
1. макрос

## <span style="background-color:green">КОМПИЛЯТОРЫ</span>
### <span style="background-color:red; color:black">GNU Compiler Collection</span>
<span style="color:violet">GCC</span> — стандартный компилятор в системах Linux (также есть версии для других платформ). Поддерживает <span style="color:orange">C</span>, <span style="color:orange">C++</span>, <span style="color:orange">Objective-C</span> и другие языки<br>

### <span style="background-color:red; color:black">Clang</span>
<span style="color:violet">Clang</span> — фронтенд для компиляторов для языков программирования C, C++, Objective-C, Objective-C++ и OpenCL C, созданный совместно с фреймворком LLVM. Цель проекта — <span style="color:orange">создание замены GNU Compiler Collection (GCC)</span>.<br>

### <span style="background-color:red; color:black">MICROSOFT VISUAL STDUIO</span>
<span style="color:violet">Microsoft Visual Studio</span> — не столько компилятор, сколько <span style="color:orange">самая популярная IDE для C/C++ на Windows</span>, но поставляется вместе с компилятором для C/C++<br>

### <span style="background-color:red; color:black">Переносимость</span>
Компиляторы не поддерживают весь спектр спецификаций стандарта C (в том числе и промежуточных). В целом, <span style="color:orange">реа­лизации C развиваются медленно, и многие компиляторы существенно отстают от стандарта языка</span>.

1. <span style="color:orange">Идеал vs Реальность</span>: Программы на C в идеале должны строго следовать стандарту для максимальной переносимости. На практике это недостижимо.

2. <span style="color:orange">Практический подход</span>: В реальности код пишут для конкретных реализаций (платформ), что позволяет использовать их особенности и не мешает работе на нескольких платформах.

3. <span style="color:orange">Проблемы переносимости</span>: Стандарт C явно выделяет пять видов поведения, которые мешают переносимости:

- <span style="color:orange">Поведение, определяемое реализацией (во избежание проблем, нужно стремиться писать код, поведение которого не будет зависеть от конкретной реализации языка (стандарт языка и компилятор))</span>
- <span style="color:orange">Неуточнённое поведение (стандарт C допускает несколько вариантов работы программы, но не указывает, какой именно должен быть выбран -> т.е. все варианты корректны, но результат выполнения - разный)</span>
- <span style="color:orange">Неопределённое поведение</span>
- <span style="color:orange">Поведение, зависящее от региональных параметров</span>
- <span style="color:orange">Распространённые расширения</span>

#### <span style="background-color:red">Неопределенное поведение</span>
<span style="color:violet">Неопределённое поведение</span> - поведение, для которого стандарт C не устанавливает никаких требований.

<span style="color:red">Сущность</span>:<br>

1. Результат непредсказуем — от некорректного вывода до сбоя программы

2. Примеры: переполнение знакового целого, разыменование некорректного указателя

3. Стандарт явно не определяет последствия таких действий

<span style="color:red">Возможные последствия:</span>:<br>

1. Непредсказуемые результаты без предупреждений

2. Поведение, специфичное для конкретной платформы

3. Аварийное завершение программы

<span style="color:orange">Нужно избегать неопределённого поведения, если только реализация явно не определяет его через расширения языка.</span>

## <span style="background-color:green">ОБЪЕКТЫ</span>

<span style="color:violet">Объект</span> — это хранилище, в котором можно представлять значения. По стандарту <span style="color:orange">ISO/IEC 9899:2018</span>, <span style="color:violet">объект</span> - область хранилища данных в среде выполнения, содержимое которого может представлять значения» с примечанием: «при обращении к объекту можно считать, что он обладает определенным типом».

<span style="color:violet">Переменная</span> - это контейнер для значения. Они имеют объявленный <span style="color:orange">тип</span>, указывающий на то, какого рода объект представляет его значение. 