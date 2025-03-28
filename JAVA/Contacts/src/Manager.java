import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class Manager {
    
    private ArrayList<People> list = new ArrayList<People>();
    private MyScanner sc = new MyScanner();
    private final int MAX_SIZE = 15;
    Scanner scanner = new Scanner(System.in);

    public void run() {
        while (true) {
            try {
                if (System.getProperty("os.name").contains("Windows"))
                    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                else
                    Runtime.getRuntime().exec("clear");
            } catch (IOException | InterruptedException ex) {}

            printMainMenu();
            int choice = sc.InputInt();
            mainChoice(choice);
            System.out.println("\n按回车键继续...");
            scanner.nextLine();
        }
    }

    private void printMainMenu() {
        System.out.println("\n=== 通信录管理系统 ===");
        System.out.println("1. 查看联系人");
        System.out.println("2. 添加联系人");
        System.out.println("3. 拨打电话");
        System.out.println("4. 修改联系人");
        System.out.println("5. 删除联系人");
        System.out.println("6. 退出系统");
    }

    private void mainChoice(int choice) {
        switch (choice) {
            case 1:
                showPeople();
                break;
            case 2:
                addPeople();
                break;
            case 3:
                call();
                break;
            case 4:
                modifyPeople();
                break;
            case 5:
                deletePeople();
                break;
            case 6:
                System.exit(0);
                break;
            default:
                System.out.println("输入错误，请重新输入");
        }
    }

    private void showPeople() {
        System.out.println("\n=== 查看联系人 ===\n");
        System.out.println("A. 办公类 \t B. 个人类 \t C. 商务类");

        String belonging = "";
        char belong = sc.InputChar('A', 'C');
        switch (belong) {
            case 'A':
                belonging = "办公类";
                break;
            case 'B':
                belonging = "个人类";
                break;
            case 'C':
                belonging = "商务类";
                break;
            default:
                belonging = "";
                System.out.println("输入错误，请重新输入");
                break;
        }

        System.out.println("编号\t姓名\t电话号码\t所属类别\t邮箱");
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getBelonging() == belonging) {
                System.out.print(i + 1 + "\t");
                System.out.print(list.get(i).getName() + "\t");
                System.out.print(list.get(i).getNumber() + "\t");
                System.out.print(belonging + "\t\t");
                System.out.print(list.get(i).getEmail() + "\n");
            }
        }
    }

    private void addPeople() {

        if (list.size() >= MAX_SIZE) {
            System.out.println("联系人数量已达上限，无法添加");
            return;
        }

        System.out.println("\n=== 添加联系人 ===\n");

        String name;
        String number;
        String belonging;
        String email;

        while (true) {
            int judge = 0;
            System.out.print("请输入姓名：");
            name = sc.InputString();

            System.out.print("请输入电话号码：");
            number = sc.InputNumber();

            System.out.print("请输入所属类别：\nA. 办公类 \t B. 个人类 \t C. 商务类\n");
            char belong = sc.InputChar('A', 'C');
            switch (belong) {
                case 'A':
                    belonging = "办公类";
                    break;
                case 'B':
                    belonging = "个人类";
                    break;
                case 'C':
                    belonging = "商务类";
                    break;
                default:
                    belonging = "";
                    System.out.println("输入错误，请重新输入");
                    break;
            }

            System.out.print("请输入邮箱：");
            email = sc.InputEmail();

            People pt = new People(name, number, belonging, email);

            if (list.contains(pt)) {
                System.out.println("联系人已存在，请重新输入");
                continue;
            }
            if (judge == 1) {
                System.out.println("输入错误，请重新输入");
                continue;
            }

            break;
        }

        People p = new People(name, number, belonging, email);

        list.add(p);

        System.out.println("联系人添加成功");
    }

    private void call() {
        System.out.println("\n=== 拨打电话 ===\n");
        showPeople();

        System.out.print("请输入要拨打的联系人编号：");
        int index = sc.InputInt(1, list.size()) - 1;

        final String phoneNumber = list.get(index).getNumber();
        final Clip[] clipHolder = new Clip[1]; // 定义一个Clip数组，用于保存铃声

        // 创建铃声播放线程
        Thread ringThread = new Thread(() -> {
            try {
                AudioInputStream audio = AudioSystem.getAudioInputStream(
                        new File("Ringtones/ring.wav").getAbsoluteFile());
                clipHolder[0] = AudioSystem.getClip();
                clipHolder[0].open(audio);
                clipHolder[0].loop(Clip.LOOP_CONTINUOUSLY); // 循环播放
            } catch (Exception ex) {
                System.err.println("铃声播放失败: " + ex.getMessage());
            }
        });

        // 创建拨号动画线程
        Thread dialThread = new Thread(() -> {
            try {
                System.out.print("\n拨号中：");
                for (char digit : phoneNumber.toCharArray()) {
                    System.out.print(digit);
                    System.out.flush();
                    Thread.sleep(500);
                }

                // 停止铃声
                if (clipHolder[0] != null) {
                    clipHolder[0].stop();
                    clipHolder[0].close();
                }

                // 播放连接音
                java.awt.Toolkit.getDefaultToolkit().beep();
                Thread.sleep(1000);
                System.out.println("\n\n通话已连接...");
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        // 启动线程
        ringThread.start();
        dialThread.start();

        // 等待拨号线程完成
        try {
            dialThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    private void modifyPeople() {

        if (list.size() == 0) {
            System.out.println("联系人列表为空，无法修改");
            return;
        }

        System.out.println("\n=== 修改联系人 ===\n");
        showPeople();

        System.out.print("请输入要修改的联系人编号：");
        int index = sc.InputInt(1, list.size()) - 1;

        System.out.print("请输入新的姓名：");
        String name = sc.InputString();
        list.get(index).setName(name);

        System.out.print("请输入新的电话号码：");
        String number = sc.InputNumber();
        list.get(index).setNumber(number);

        System.out.print("请输入新的所属类别：\nA. 办公类 \t B. 个人类 \t C. 商务类\n");
        char belong = sc.InputChar('A', 'C');
        String belonging = "";
        switch (belong) {
            case 'A':
                belonging = "办公类";
                break;
            case 'B':
                belonging = "个人类";
                break;
            case 'C':
                belonging = "商务类";
                break;
            default:
                System.out.println("输入错误，请重新输入");
                break;
        }
        list.get(index).setBelonging(belonging);

        System.out.print("请输入新的邮箱：");
        String email = sc.InputEmail();
        list.get(index).setEmail(email);

        System.out.println("联系人修改成功");
    }

    private void deletePeople() {

        if (list.size() == 0) {
            System.out.println("联系人列表为空，无法删除");
            return;
        }

        System.out.println("\n=== 删除联系人 ===\n");
        showPeople();

        System.out.print("请输入要删除的联系人编号：");
        int index = sc.InputInt(1, list.size()) - 1;

        list.remove(index);

        System.out.println("联系人删除成功");
    }

}
