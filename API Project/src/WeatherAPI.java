import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import java.util.stream.Collectors;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

public class WeatherAPI {
	 public static void main(String[] args) throws IOException{ 
		Scanner scan = new Scanner(System.in);
		// Ask user: What city are you looking for? 
		System.out.println("Enter a city or zip to retrieve the temperature from.");
		String userInput = scan.nextLine();
		
		String temp = getWeather(getURL(userInput));  //this function will return the temperature
		System.out.printf("%s is currently %s", userInput, temp);
		scan.close();
	}
	
	//Function that will parse the JSON 
	public static String getWeather(String city){
		JsonObject object = new JsonParser().parse(city).getAsJsonObject();
		JsonObject main = object.getAsJsonObject("main");
		Double temp = main.get("temp").getAsDouble();
		temp = (temp*9)/5 - 459.67;
		String tempString = String.format("%.2f", temp);
		tempString += "°F.";
		
		return tempString;
	}
	//Function for converting  the city/zip string to the url to request the JSON formatted information for said city/zip
	public static String getURL(String string) throws IOException{
		String myApiToken = "&APPID=26aa1d90a24c98fad4beaac70ddbf274";
		String myAPIurl = "http://api.openweathermap.org/data/2.5/weather?q=";
		String weatherURL = myAPIurl + string + myApiToken; 
		URL url = new URL(weatherURL);
		HttpURLConnection conn = (HttpURLConnection) url.openConnection();
		conn.setRequestMethod("GET");
		BufferedReader rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
		// Convert rd variable from BufferReader to String and store in variable called result. 
		String result = rd.lines().collect(Collectors.joining());
		return result;
	}
}