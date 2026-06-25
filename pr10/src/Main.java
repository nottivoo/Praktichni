import java.util.Scanner;

class MyCustomException extends Exception {
    public MyCustomException(String message) {
        super(message);
    }
}

class LimitException extends MyCustomException {
    public LimitException(String message) {
        super(message);
    }
}

class ValidationError extends MyCustomException {
    public ValidationError(String message) {
        super(message);
    }
}

class LoginException extends MyCustomException {
    public LoginException(String message) {
        super(message);
    }
}

public class Main {
    static String[] users = new String[15];
    static String[] passwords = new String[15];
    static int currentUsersCount = 0;
    static String[] bannedWords = {"admin", "pass", "password", "qwerty", "ytrewq"};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n=== МЕНЮ СИСТЕМИ ===");
            System.out.println("1. Реєстрація нового користувача");
            System.out.println("2. Видалення користувача за ім'ям");
            System.out.println("3. Виконати дію (Аутентифікація)");
            System.out.println("4. Вихід з програми");
            System.out.print("Оберіть дію: ");

            String choice = scanner.nextLine();

            try {
                if (choice.equals("1")) {
                    register(scanner);
                } else if (choice.equals("2")) {
                    delete(scanner);
                } else if (choice.equals("3")) {
                    login(scanner);
                } else if (choice.equals("4")) {
                    System.out.println("Програму завершено.");
                    break;
                } else {
                    System.out.println("Неправильний вибір, спробуйте ще раз.");
                }
            } catch (LimitException e) {
                System.out.println("[ПОМИЛКА ЛІМІТУ]: " + e.getMessage());
            } catch (ValidationError e) {
                System.out.println("[ПОМИЛКА ВАЛІДАЦІЇ]: " + e.getMessage());
            } catch (LoginException e) {
                System.out.println("[ПОМИЛКА ВХОДУ]: " + e.getMessage());
            } catch (MyCustomException e) {
                System.out.println("[ПОМИЛКА СИСТЕМИ]: " + e.getMessage());
            }
        }
    }

    public static void register(Scanner sc) throws MyCustomException {
        if (currentUsersCount >= 15) {
            throw new LimitException("Досягнуто ліміт користувачів (макс. 15). Додати 16-го не можна!");
        }

        System.out.print("Введіть логін: ");
        String name = sc.nextLine();
        checkLoginRules(name);

        System.out.print("Введіть пароль: ");
        String pass = sc.nextLine();
        checkPasswordRules(pass);

        for (int i = 0; i < 15; i++) {
            if (users[i] == null) {
                users[i] = name;
                passwords[i] = pass;
                currentUsersCount++;
                System.out.println("Користувач '" + name + "' успішно доданий!");
                return;
            }
        }
    }

    public static void delete(Scanner sc) throws MyCustomException {
        System.out.print("Введіть ім'я користувача для видалення: ");
        String name = sc.nextLine();

        for (int i = 0; i < 15; i++) {
            if (users[i] != null && users[i].equals(name)) {
                users[i] = null;
                passwords[i] = null;
                currentUsersCount--;
                System.out.println("Користувача '" + name + "' успішно видалено. Звільнилося місце.");
                return;
            }
        }
        throw new LoginException("Користувача з таким ім'ям не знайдено!");
    }

    public static void login(Scanner sc) throws MyCustomException {
        System.out.print("Логін: ");
        String name = sc.nextLine();
        System.out.print("Пароль: ");
        String pass = sc.nextLine();

        for (int i = 0; i < 15; i++) {
            if (users[i] != null && users[i].equals(name)) {
                if (passwords[i].equals(pass)) {
                    System.out.println("Користувач '" + name + "' успішно аутентифікований!");
                    return;
                } else {
                    throw new LoginException("Неправильний пароль для користувача '" + name + "'.");
                }
            }
        }
        throw new LoginException("Такого користувача не існує.");
    }

    public static void checkLoginRules(String name) throws ValidationError {
        if (name.length() < 5) {
            throw new ValidationError("Логін має бути не менше 5 символів.");
        }
        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) == ' ') {
                throw new ValidationError("Логін не може містити пробіли.");
            }
        }
    }

    public static void checkPasswordRules(String pass) throws ValidationError {
        if (pass.length() < 10) {
            throw new ValidationError("Пароль має бути не менше 10 символів.");
        }

        boolean hasSpecial = false;
        int digitCount = 0;
        String specChars = "!@#$%^&*()-_=+[{]};:'\",<.>/?\\|`~";

        for (int i = 0; i < pass.length(); i++) {
            char c = pass.charAt(i);

            if (c == ' ') {
                throw new ValidationError("Пароль не повинен містити пробіли.");
            }

            boolean isLatin = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
            boolean isDigit = (c >= '0' && c <= '9');

            boolean isSpec = false;
            for (int j = 0; j < specChars.length(); j++) {
                if (specChars.charAt(j) == c) {
                    isSpec = true;
                    break;
                }
            }

            if (isDigit) {
                digitCount++;
            }
            if (isSpec) {
                hasSpecial = true;
            }

            if (!isLatin && !isDigit && !isSpec) {
                throw new ValidationError("Пароль може містити тільки латинські літери, цифри та спецсимволи.");
            }
        }

        if (!hasSpecial) {
            throw new ValidationError("Пароль повинен містити хоча б 1 спеціальний символ.");
        }
        if (digitCount < 3) {
            throw new ValidationError("Пароль повинен містити мінімум 3 цифри.");
        }

        for (int i = 0; i < bannedWords.length; i++) {
            if (myContains(pass, bannedWords[i])) {
                throw new ValidationError("Пароль містить заборонене слово: " + bannedWords[i]);
            }
        }
    }

    public static boolean myContains(String text, String word) {
        if (word.length() > text.length()) return false;

        for (int i = 0; i <= text.length() - word.length(); i++) {
            boolean found = true;
            for (int j = 0; j < word.length(); j++) {
                if (text.charAt(i + j) != word.charAt(j)) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        return false;
    }
}