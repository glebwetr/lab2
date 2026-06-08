Лабораторная работа №2
Системы контроля версий. Git.
Студент: Глеб (glebwetr)
Репозиторий: github.com/glebwetr/lab2

Цель работы
Изучить систему контроля версий Git на практике: научиться создавать репозитории, делать коммиты, работать с ветками и pull request'ами, разрешать конфликты при слиянии.

Основная часть (Tutorial)
Шаг 1. Инициализация репозитория и первый коммит README.md
Создан публичный репозиторий lab2 на GitHub. Выполнена глобальная настройка Git:

bash
git config --global user.name "glebwetr"
git config --global user.email "<ваш email>"
Добавлен файл README.md с описанием лабораторной работы и сделан первый коммит.

bash
git add README.md
git commit -m "added README.md"
git push origin main
Результат:

text
[main 1a2b3c4] added README.md
 1 file changed, 3 insertions(+)
 create mode 100644 README.md
Шаг 2. Добавление файла .gitignore
На GitHub создан файл .gitignore со следующим содержимым:

gitignore
*build*/
*install*/
*.swp
.idea/
bash
git add .gitignore
git commit -m "added .gitignore"
git push origin main
Шаг 3. Добавление исходного кода (sources / include / examples)
Созданы директории sources/, include/, examples/ и добавлены файлы:

sources/print.cpp — реализация функции print

include/print.hpp — заголовочный файл

examples/example1.cpp и examples/example2.cpp — примеры использования

bash
git add sources/ include/ examples/
git commit -m "added sources"
git push origin main
Домашнее задание
Part I — Hello World
Шаг 1–2. Создание hello_world.cpp с плохим стилем кода
Создан файл hello_world.cpp с намеренно плохим стилем — использование using namespace std;:

cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "Hello world" << endl;
  return 0;
}
bash
git add hello_world.cpp
git commit -m "add hello_world with bad code style"
git push origin main
Шаг 3. Обновление программы: ввод имени пользователя
Программа обновлена — теперь запрашивает имя через stdin и выводит Hello world from @name.

bash
git add hello_world.cpp
git commit -m "feat: request name from stdin, print Hello world from @name"
git push origin main
Part II — Ветка patch1
Шаг 1. Создание локальной ветки patch1
bash
git checkout -b patch1
git push origin patch1
Шаг 2–3. Исправление кода и добавление комментариев
В ветке patch1 выполнено два коммита:

fix: remove using namespace std — убран плохой стиль кода

docs: add inline comments — добавлены поясняющие комментарии

bash
git commit -m "fix: remove using namespace std"
git push origin patch1

git commit -m "docs: add inline comments"
git push origin patch1
Шаг 4. Pull Request patch1 → main
Создан PR #1 patch1 -> main: fix code style (конфликтов нет).

Шаг 5. Слияние PR и удаление ветки
PR успешно смержен, ветка patch1 удалена в удалённом репозитории.

Part III — Ветка patch2
Шаг 1–2. Создание ветки patch2 и применение clang-format
Создана ветка patch2. К файлу hello_world.cpp применён форматтер clang-format со стилем Mozilla:

bash
git checkout -b patch2
git commit -m "style: apply clang-format Mozilla style"
git push origin patch2
Шаг 3. Pull Request patch2 → main и конфликты
Создан PR #2 patch2 -> main: clang-format. Параллельно в ветке main были изменены комментарии (переведены на английский язык), что создало конфликт.

bash
git checkout main
git commit -m "docs: translate comments to English"
git push origin main
Шаг 4. Разрешение конфликтов через rebase
Конфликт разрешён вручную, изменения приняты. Финальный коммит в patch2:

bash
git commit -m "fix: resolve rebase conflict — Mozilla style + English comments"
git push origin patch2
Шаг 5. Слияние PR patch2 → main
PR #2 смержен, ветка patch2 удалена.

Итоговое состояние репозитория
На момент сдачи отчёта в репозитории присутствуют:

Все основные файлы проекта (README.md, .gitignore, hello_world.cpp, файлы в sources/, include/, examples/)

17 коммитов с понятными сообщениями

Два успешно закрытых pull request (ветки patch1 и patch2 удалены)

Итоговый hello_world.cpp соответствует стилю Mozilla и содержит комментарии на английском языке

Добавлен файл отчёта lab02_report (1).md

Язык исходного кода: C++ 100%
