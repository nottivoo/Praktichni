import java.util.Scanner;

class InvalidMenuOptionException extends Exception {
    public InvalidMenuOptionException(String message) {
        super(message);
    }
}

class NotANumberException extends Exception {
    public NotANumberException(String message) {
        super(message);
    }
}

class CellOccupiedException extends Exception {
    public CellOccupiedException(String message) {
        super(message);
    }
}

class OutOfBoundsException extends Exception {
    public OutOfBoundsException(String message) {
        super(message);
    }
}

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int fieldSize = 3;

        while (true) {
            try {
                System.out.println("\n   Меню");
                System.out.println("1. Старт");
                System.out.println("2. Налаштування");
                System.out.println("3. Правила");
                System.out.println("4. Вихід");
                System.out.print("Оберіть пункт меню: ");

                int choice = readInt();

                if (choice == 1) {
                    startGame(fieldSize);
                } else if (choice == 2) {
                    fieldSize = settingsMenu(fieldSize);
                } else if (choice == 3) {
                    showRules();
                } else if (choice == 4) {
                    System.out.println("Вихід");
                    break;
                } else {
                    throw new InvalidMenuOptionException("Такого пункту меню не існує!");
                }
            } catch (InvalidMenuOptionException | NotANumberException e) {
                System.out.println("Помилка: " + e.getMessage());
            }
        }
    }

    private static int readInt() throws NotANumberException {
        if (!scanner.hasNextInt()) {
            scanner.next();
            throw new NotANumberException("Введено не число! Використовуйте цифри.");
        }
        return scanner.nextInt();
    }

    private static void startGame(int fieldSize) {
        char[][] board = new char[fieldSize][fieldSize];
        for (int i = 0; i < fieldSize; i++) {
            for (int j = 0; j < fieldSize; j++) {
                board[i][j] = ' ';
            }
        }

        char currentPlayer = 'X';
        while (true) {
            printBoard(board, fieldSize);
            try {
                System.out.println("Гравець " + currentPlayer + ", введіть номер рядка (1-" + fieldSize + "):");
                int row = readInt() - 1;
                System.out.println("Гравець " + currentPlayer + ", введіть номер стовпця (1-" + fieldSize + "):");
                int col = readInt() - 1;

                if (row < 0 || row >= fieldSize || col < 0 || col >= fieldSize) {
                    throw new OutOfBoundsException("Координати поза межами поля!");
                }
                if (board[row][col] != ' ') {
                    throw new CellOccupiedException("Ця клітинка вже зайнята!");
                }

                board[row][col] = currentPlayer;

                if (checkWinner(board, fieldSize, currentPlayer)) {
                    printBoard(board, fieldSize);
                    System.out.println("Вітаю! Гравець " + currentPlayer + " виграв!");
                    break;
                }

                if (isBoardFull(board, fieldSize)) {
                    printBoard(board, fieldSize);
                    System.out.println("Нічия!");
                    break;
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

            } catch (NotANumberException | OutOfBoundsException | CellOccupiedException e) {
                System.out.println("Помилка: " + e.getMessage());
            }
        }
    }

    private static int settingsMenu(int currentSize) throws NotANumberException {
        System.out.println("Налаштування:");
        System.out.println("1. 3x3\n2. 5x5\n3. 7x7\n4. 9x9\n0. Назад");
        int sChoice = readInt();
        switch (sChoice) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 7;
            case 4: return 9;
            case 0: return currentSize;
            default: return currentSize;
        }
    }

    private static void showRules() {
        System.out.println("Правила: 3 фігури в ряд для перемоги. Хрестик ходить першим.");
    }

    private static void printBoard(char[][] board, int size) {
        System.out.print("  ");
        for (int j = 1; j <= size; j++) System.out.print(j + "   ");
        System.out.println();
        for (int i = 0; i < size; i++) {
            System.out.print((i + 1) + "|");
            for (int j = 0; j < size; j++) {
                System.out.print(" " + board[i][j] + " |");
            }
            System.out.println();
        }
    }

    private static boolean checkWinner(char[][] b, int size, char p) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j <= size - 3 && b[i][j] == p && b[i][j+1] == p && b[i][j+2] == p) return true;
                if (i <= size - 3 && b[i][j] == p && b[i+1][j] == p && b[i+2][j] == p) return true;
                if (i <= size - 3 && j <= size - 3 && b[i][j] == p && b[i+1][j+1] == p && b[i+2][j+2] == p) return true;
                if (i <= size - 3 && j >= 2 && b[i][j] == p && b[i+1][j-1] == p && b[i+2][j-2] == p) return true;
            }
        }
        return false;
    }

    private static boolean isBoardFull(char[][] b, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (b[i][j] == ' ') return false;
            }
        }
        return true;
    }
}
