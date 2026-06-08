# Лабораторная работа №2
## Системы контроля версий. Git.

---

## Цель работы

Изучить систему контроля версий Git на практике: научиться создавать репозитории, делать коммиты, работать с ветками и pull request'ами, разрешать конфликты при слиянии.

---

## Основная часть (Tutorial)

### Шаг 1. Инициализация репозитория и первый коммит README.md

Создан публичный репозиторий `lab2` на GitHub с лицензией MIT. Выполнена глобальная настройка git:

```
git config --global user.name operatordoto
git config --global user.email foxes_lore@mail.ru
```

Добавлен файл `README.md` с описанием лабораторной работы и сделан первый коммит.

```
git add README.md
git commit -m "added README.md"
git push origin main
```

```
[main 90c88d7] added README.md
 1 file changed, 3 insertions(+)
 create mode 100644 README.md
To https://github.com/operatordoto/fluffy-octo-dollop
   42a6136..90c88d7  main -> main
```



---

### Шаг 2. Добавление файла .gitignore

На GitHub создан файл `.gitignore` со следующим содержимым:

```
*build*/
*install*/
*.swp
.idea/
```

```
git add .gitignore
git commit -m "added .gitignore"
git push origin main
```

```
[main a49c55b] added .gitignore
 1 file changed, 4 insertions(+)
 create mode 100644 .gitignore
To https://github.com/operatordoto/fluffy-octo-dollop
   90c88d7..a49c55b  main -> main
```



---

### Шаг 3. Добавление исходного кода (sources / include / examples)

Созданы директории `sources/`, `include/`, `examples/` и добавлены файлы:

- `sources/print.cpp` — реализация функции `print`
- `include/print.hpp` — заголовочный файл
- `examples/example1.cpp` и `examples/example2.cpp` — примеры использования

```
git add sources/ include/ examples/
git commit -m "added sources"
git push origin main
```

```
[main 722bf39] added sources
 4 files changed, 31 insertions(+)
 create mode 100644 examples/example1.cpp
 create mode 100644 examples/example2.cpp
 create mode 100644 include/print.hpp
 create mode 100644 sources/print.cpp
To https://github.com/operatordoto/fluffy-octo-dollop
   a49c55b..722bf39  main -> main
```





---

## Домашнее задание

### Part I — Hello World

#### Шаг 1–2. Создание hello_world.cpp с плохим стилем кода

Создан файл `hello_world.cpp` с намеренно плохим стилем — использование `using namespace std;`:

```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "Hello world" << endl;
  return 0;
}
```

```
git add hello_world.cpp
git commit -m "add hello_world with bad code style"
git push origin main
```

```
[main 781e958] add hello_world with bad code style
 1 file changed, 8 insertions(+)
 create mode 100644 hello_world.cpp
To https://github.com/operatordoto/fluffy-octo-dollop
   722bf39..781e958  main -> main
```



#### Шаг 3. Обновление программы: ввод имени пользователя

Программа обновлена — теперь запрашивает имя через `stdin` и выводит `Hello world from @name`. Повторный `git add` не нужен, т.к. файл уже отслеживается Git'ом — он добавляется повторно только при первом появлении нового файла.

```
git add hello_world.cpp
git commit -m "feat: request name from stdin, print Hello world from @name"
git push origin main
```

```
[main 2614473] feat: request name from stdin, print Hello world from @name
 1 file changed, 4 insertions(+), 1 deletion(-)
To https://github.com/operatordoto/fluffy-octo-dollop
   781e958..2614473  main -> main
```



---

### Part II — Ветка patch1

#### Шаг 1. Создание локальной ветки patch1

```
git checkout -b patch1
git push origin patch1
```

```
Switched to a new branch 'patch1'
To https://github.com/operatordoto/fluffy-octo-dollop
 * [new branch]      patch1 -> patch1
```



#### Шаг 2–3. Исправление кода и добавление комментариев

В ветке `patch1` выполнено два коммита:
- `fix: remove using namespace std` — убран плохой стиль кода
- `docs: add inline comments` — добавлены поясняющие комментарии

```
git add hello_world.cpp
git commit -m "fix: remove using namespace std"
git push origin patch1
```

```
[patch1 60496ef] fix: remove using namespace std
 1 file changed, 5 insertions(+), 5 deletions(-)
To https://github.com/operatordoto/fluffy-octo-dollop
   2614473..60496ef  patch1 -> patch1
```

```
git add hello_world.cpp
git commit -m "docs: add inline comments"
git push origin patch1
```

```
[patch1 3a42940] docs: add inline comments
 1 file changed, 2 insertions(+)
To https://github.com/operatordoto/fluffy-octo-dollop
   60496ef..3a42940  patch1 -> patch1
```



#### Шаг 4. Pull Request patch1 → main

Создан PR #1 `patch1 -> main: fix code style`. PR содержит оба коммита, конфликтов нет.

```
gh pr create --title "patch1 -> main: fix code style" \
  --body "- Remove using namespace std\n- Add inline comments" \
  --head patch1 --base main
```

```
https://github.com/operatordoto/fluffy-octo-dollop/pull/1
```



#### Шаг 5. Слияние PR и удаление ветки

PR успешно смержен, ветка `patch1` удалена в удалённом репозитории.

```
gh pr merge patch1 --merge --delete-branch
```

```
Updating 2614473..aa029d4
Fast-forward
 hello_world.cpp | 12 +++++++-----
 1 file changed, 7 insertions(+), 5 deletions(-)
```



---

### Part III — Ветка patch2

#### Шаг 1–2. Создание ветки patch2 и применение clang-format

Создана ветка `patch2`. К файлу `hello_world.cpp` применён форматтер `clang-format` со стилем Mozilla:

```
git checkout -b patch2
git add hello_world.cpp
git commit -m "style: apply clang-format Mozilla style"
git push origin patch2
```

```
Switched to a new branch 'patch2'
[patch2 dc93e57] style: apply clang-format Mozilla style
 1 file changed, 2 insertions(+), 1 deletion(-)
To https://github.com/operatordoto/fluffy-octo-dollop
 * [new branch]      patch2 -> patch2
```

#### Шаг 3. Pull Request patch2 → main и конфликты

Создан PR #2 `patch2 -> main: clang-format`. Параллельно в ветке `main` были изменены комментарии (переведены на английский язык), что создало конфликт.

```
git checkout main
git add hello_world.cpp
git commit -m "docs: translate comments to English"
git push origin main
```

```
[main 97211d6] docs: translate comments to English
 1 file changed, 2 insertions(+), 2 deletions(-)
To https://github.com/operatordoto/fluffy-octo-dollop
   aa029d4..97211d6  main -> main
```

```
gh pr create --title "patch2 -> main: clang-format" \
  --body "Apply Mozilla clang-format style" \
  --head patch2 --base main
```

```
https://github.com/operatordoto/fluffy-octo-dollop/pull/2
```



#### Шаг 4. Разрешение конфликтов через rebase

```
git checkout patch2
git add hello_world.cpp
git commit -m "fix: resolve rebase conflict — Mozilla style + English comments"
git push origin patch2
```

```
[patch2 3d53b5e] fix: resolve rebase conflict — Mozilla style + English comments
 1 file changed, 2 insertions(+), 2 deletions(-)
To https://github.com/operatordoto/fluffy-octo-dollop
   dc93e57..3d53b5e  patch2 -> patch2
```



#### Шаг 5. Слияние PR patch2 → main

PR #2 смержен, ветка `patch2` удалена.

```
gh pr merge patch2 --merge --delete-branch
```

```
Updating 97211d6..563af60
Fast-forward
 hello_world.cpp | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)
```



---

**Ссылка на репозиторий:** https://github.com/operatordoto/fluffy-octo-dollop
