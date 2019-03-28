import java.io.IOException;
import java.util.Scanner;

public class test {
	 public static void main(String[] args) throws IOException {
		 Scanner scan = new Scanner(System.in);
		 String request = scan.nextLine();
		 String city = request.substring(0);
		 request = scan.nextLine();
		 String mod = request.substring(0);
		 System.out.println(WeatherAPI.getWeather(WeatherAPI.getURL(city)));
		 System.out.println(NexusModsAPI.getMods(NexusModsAPI.getURL(mod)));
		 scan.close();
	 }
}
