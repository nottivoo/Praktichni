import java.util.Scanner;

class UserLimitException extends Exception {
    public UserLimitException(String message) { super(message); }
}

class InvalidUsernameException extends Exception {
    public InvalidUsernameException(String message) { super(message); }
}

class InvalidPasswordException extends Exception {
    public InvalidPasswordException(String message) { super(message); }
}

class UserNotFoundException extends Exception {
    public UserNotFoundException(String message) { super(message); }
}

class AuthenticationException extends Exception {
    public AuthenticationException(String message) { super(message); }
}

public class UserAuthSystem {
    private static final int MAX_USERS = 15;
    private String[] usernames = new String[MAX_USERS];
    private String[] passwords = new String[MAX_USERS];
    private String[] bannedPasswords = {"admin", "pass", "password", "qwerty", "ytrewq"};
    private int userCount = 0;

    public static void main(String[] args) {
        UserAuthSystem system = new UserAuthSystem();
        system.runMenu();
    }

    public void runMenu() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\n1 - Додати користувача\n2 - Видалити\n3 - Виконати дію (Вхід)\n4 - Вихід");
            try {
                String input = scanner.nextLine();
                int choice = Integer.parseInt(input);
                if (choice == 1) registerUser(scanner);
                else if (choice == 2) deleteUser(scanner);
                else if (choice == 3) authenticateUser(scanner);
                else if (choice == 4) break;
            } catch (NumberFormatException e) {
                System.out.println("Помилка: введіть число");
            } catch (UserLimitException | InvalidUsernameException | InvalidPasswordException |
                     UserNotFoundException | AuthenticationException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    private void registerUser(Scanner sc) throws UserLimitException, InvalidUsernameException, InvalidPasswordException {
        if (userCount >= MAX_USERS) {
            throw new UserLimitException("Помилка: ліміт 15 користувачів");
        }

        System.out.print("Username: ");
        String name = sc.nextLine();
        validateUsername(name);

        System.out.print("Password: ");
        String pass = sc.nextLine();
        validatePassword(pass);

        for (int i = 0; i < MAX_USERS; i++) {
            if (usernames[i] == null) {
                usernames[i] = name;
                passwords[i] = pass;
                userCount++;
                break;
            }
        }
    }

    private void validateUsername(String name) throws InvalidUsernameException {
        if (name.length() < 5) throw new InvalidUsernameException("Помилка: ім'я < 5 символів");
        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) == ' ') throw new InvalidUsernameException("Помилка: ім'я має пробіл");
        }
    }

    private void validatePassword(String pass) throws InvalidPasswordException {
        if (pass.length() < 10) throw new InvalidPasswordException("Помилка: пароль < 10 символів");

        int digits = 0;
        boolean hasSpecial = false;
        String specialChars = "!@#$%^&*()-_=+[]{};:'\",.<>/?|\\";

        for (int i = 0; i < pass.length(); i++) {
            char c = pass.charAt(i);
            if (c == ' ') throw new InvalidPasswordException("Помилка: пароль має пробіл");
            if (Character.isDigit(c)) digits++;
            if (specialChars.indexOf(c) >= 0) hasSpecial = true;
        }

        if (digits < 3) throw new InvalidPasswordException("Помилка: треба мінімум 3 цифри");
        if (!hasSpecial) throw new InvalidPasswordException("Помилка: треба мінімум 1 спецсимвол");

        String lowerPass = pass.toLowerCase();
        for (String banned : bannedPasswords) {
            if (lowerPass.contains(banned)) {
                throw new InvalidPasswordException("Помилка: заборонене слово " + banned);
            }
        }
    }

    private void deleteUser(Scanner sc) throws UserNotFoundException {
        System.out.print("Name to delete: ");
        String name = sc.nextLine();
        for (int i = 0; i < MAX_USERS; i++) {
            if (name.equals(usernames[i])) {
                usernames[i] = null;
                passwords[i] = null;
                userCount--;
                return;
            }
        }
        throw new UserNotFoundException("Помилка: користувача не знайдено");
    }

    private void authenticateUser(Scanner sc) throws AuthenticationException {
        System.out.print("Login: ");
        String name = sc.nextLine();
        System.out.print("Pass: ");
        String pass = sc.nextLine();

        for (int i = 0; i < MAX_USERS; i++) {
            if (name.equals(usernames[i]) && pass.equals(passwords[i])) {
                System.out.println("Користувача було аутентифіковано");
                return;
            }
        }
        throw new AuthenticationException("Помилка: логін або пароль невірні");
    }
}