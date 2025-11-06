> <span style="background-color: green">Можно компилиривать как при помощи gcc, так и cc - второй слздаст файл a.out. Или, как у gcc, можно добавить флаг -o и скомпилить файл с нужным именем.</span>

> C имеет две потенциальные <span style="color:orange">среды выполнения:
1. <span style="color:orange">минимальную - freestanding</span>
2. <span style="color:orange">полноценную - hosted</span><br>

> <span style="background-color:red; color:black">---Минимальная среда выполнения---</span>
1. Может существовать вне ОС
2. Используется в создании встраиваемых систем
3. Предоставляет минимальный набор библиотечных функций, а объявление точки входа отличается в разных реализациях

> Программы на C состоят из <span style="color:orange">процедур (функций, методов)</span>, которые:
1. имеют определённый тип и могут возвращять определённые значения (тип функции = тип возвращаемого значения)
2. могут принимать аргументы

# <span style="background-color:green">Директивы препроцессора</span><br>
<span style="color:violet">#include</span> - ведет себя так, будто вместо нее подставляется содержимое указанного файла. По сути, подключает нужный файл.

# <span style="background-color:green">Стандартные библиотеки</span><br>

<span style="color:violet">stdio.h</span> - I/O - содержит методы ввода/вывода.<br>
<span style="color:violet">stdlib.h</span> - функции общего назначения.<br>

# <span style="background-color:green">Входная точка программы</span>

<span style="color:violet">int main()</span>  - входная точка программы<br>
<span style="color:violet">(void)</span> - даёт понять, что main <span style="color:orange">ничего не принимает.</span>

Предназанчение возаращемого функцией main значения - <span style="color:orange">указать, как завершилась программа - успешно или нет</span>

## <span style="background-color:red; color:black">---Как происходит вход/выход в/из программы:---</span><br>

### ВХОД 
main - входная точка, выполняемая при запуске программы
выполняется функция main в серверной среде, после запуска из командной строки или другой программы

### ВЫХОД 
return (0 или 1, или макросы, представляющие эти значения) - выход из программы -- среда исполнения получает возврат из функции main, по которому может проверить состояние проги и определить, насколько успешен был вызов.

### ЗАМЕЧАНИЯ 
return __value__ в main = exit(__value__) 

# <span style="background-color:green">ФОРМАТИРОВАННЫЙ ВЫВОД</span><br>

<span style="color:violet">printf</span> (или ее вариации) - функция, для форматированного вывода. Принимает строку, которая описывет формат вывода и произвольное количество аргументов, представляющих значения для вывода

## <span style="background-color:red; color:black">__Спецификаторы формата__</span> (не все)
1. <span style="color:violet">%s</span> - спецификатор формата, позволяющая вывести очередной аргумент - <span style="color:orange">строку</span>
2. <span style="color:violet">%d</span> - спецификатор формата, позволяющая вывести очередной аргумент - <span style="color:orange">целое число</span>
3. <span style="color:violet">%f</span> - спецификатор формата, позволяющая вывести очередной аргумент - <span style="color:orange">число с плавающей точкой</span>
4. <span style="color:violet">%c</span> - спецификатор формата, позволяющая вывести очередной аргумент - <span style="color:orange">символ</span>
5. <span style="color:violet">%x</span> - спецификатор формата, позволяющая вывести очередной аргумент - <span style="color:orange">шестнадцатиричное число</span>

## <span style="background-color:red; color:black">Алфавитные управляющие последовательности</span>
Необходимы для вывода неотображаемых символов. Список последовательностей:
1. <span style="color:violet">\n</span> - перевод строки

# <span style="background-color:green">БИБЛИОТЕЧНЫЕ МЕТОДЫ И МАКРОСЫ</span>

<span style="color:violet">int puts(const char*)</span>
1. записывает полученный аргумент в поток <span style="color:orange">stdout (консоль или терминал)</span>, добавляя к выводу '\n'
2. если во время вывода возникла ошибка, возвращается макрос EOF (представляющий отрицательное число) - иначе целое неотрицательное значение
    
<span style="color:violet">**EXIT_SUCCESS**</span>
1. макрос, зачастую имеет такое определение - #define EXIT_SUCCESS 0

<span style="color:violet">EOF</span>
1. макрос