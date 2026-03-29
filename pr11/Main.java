import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    private static String fileName = "notes.txt";

    public static void main(String[] args) {
        while (true) {
            System.out.println("\n--- Текстовий редактор ---");
            System.out.println("1. Записати до файлу");
            System.out.println("2. Прочитати увесь вміст файлу");
            System.out.println("3. Вийти з редактора");
            System.out.print("Оберіть дію: ");

            String choice = scanner.nextLine();

            if (choice.equals("1")) {
                writeToFile();
            } else if (choice.equals("2")) {
                readFromFile();
            } else if (choice.equals("3")) {
                System.out.println("Вихід...");
                break;
            } else {
                System.out.println("Помилка: Невірний вибір. Спробуйте ще раз.");
            }
        }
    }

    public static void writeToFile() {
        System.out.print("Введіть рядок для запису: ");
        String text = scanner.nextLine();

        try {
            FileWriter writer = new FileWriter(fileName, true);
            writer.write(text + "\n");
            writer.close();
            System.out.println("Запис успішно додано.");
        } catch (IOException e) {
            System.out.println("Виникла помилка при записі: " + e.getMessage());
        }
    }

    public static void readFromFile() {
        File file = new File(fileName);
        try {
            Scanner fileReader = new Scanner(file);
            System.out.println("\n--- Вміст файлу ---");
            if (!fileReader.hasNextLine()) {
                System.out.println("(Файл порожній)");
            }
            while (fileReader.hasNextLine()) {
                String data = fileReader.nextLine();
                System.out.println(data);
            }
            fileReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Помилка: Файл '" + fileName + "' ще не створено.");
        } catch (Exception e) {
            System.out.println("Сталася непередбачена помилка: " + e.getMessage());
        }
    }
}
