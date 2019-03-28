import java.util.Scanner;

public class ChatBotMain {
    
    public static void main(String[] args) throws Exception {
    	Scanner scan = new Scanner(System.in);
    	System.out.println("Choose a name for the chatbot.");
    	String name = scan.next();
        //Starts bot up.
        ChatBot bot = new ChatBot(name);
        //Enable debugging output.
        bot.setVerbose(true);
        //Connect to the IRC server.
        bot.connect("irc.freenode.net");
        //Join the #pircbot channel.
        bot.joinChannel("#pircbot");
        
        scan.close();
    }
    
}
