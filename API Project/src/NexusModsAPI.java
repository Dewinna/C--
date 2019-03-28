import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import java.util.stream.Collectors;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;


public class NexusModsAPI {
	public static void main(String[] args) throws IOException{ 
		Scanner scan = new Scanner(System.in);
		
		// Ask user: What game do you want mods for?
		System.out.println("Enter a game to retrieve 10 trending mods for. (ex. Skyrim, Fallout4, NewVegas, Witcher3)");
		String userInput = scan.nextLine();
		String result = getMods(getURL(userInput));
		System.out.print(result);
		scan.close();
	}
	//Function that will parse the JSON 
	public static String getMods(String game){
		String modName[] = new String[10];
		String modSum[] = new String[10];
		JsonArray arr = new JsonParser().parse(game).getAsJsonArray();
		//print out object and see what is inside of it 
		//If this doesn’t make sense - take another look at the JSON Response I provided on Slide 5
		for(int i = 0; i < arr.size(); i++) {
			JsonObject obj = arr.get(i).getAsJsonObject();
			modName[i] = obj.get("name").getAsString();
			modSum[i] = obj.get("summary").getAsString();
		}
		String result = "";
		for(int i = 0; i < 10; i++) {
			result += "Mod #" + (i + 1) + "\n";
			result += "Name: " + modName[i] + "\n";
			result += "Summary: " + modSum[i] + "\n\n";
		}
		return result;
	}
	public static String getMod(String name, int index) {
		String modName[] = new String[10];
		String modSum[] = new String[10];
		JsonArray arr = new JsonParser().parse(name).getAsJsonArray();
		for(int i = 0; i < arr.size(); i++) {
			JsonObject obj = arr.get(i).getAsJsonObject();
			modName[i] = obj.get("name").getAsString();
			modSum[i] = obj.get("summary").getAsString();
		}
		String result = "";
		result += "Mod #" + (index) + ": |" + modName[index - 1] + "| Details: " + modSum[index - 1];
		return result;
	}
	//Function for converting  the game string to the url to request the JSON formatted information for said game
	public static String getURL(String string) throws IOException{
		String myApiToken = "/mods/trending.json";
		String apikey = "UzdsMzZUNzQvWDJpYWM3cVMzbDBhdGsrRFpVVmFjMFdXTmIyK3p1bFlUTkpKaStJVFdBVnpyUk9YSjVPRXpPRS0tTTg0T3p2ZzVQQ3YwMkN2Ylg2WXdoQT09--52f8ecb6f91c282031c91a42ff4c7db198726146";
		String APIurl = "https://api.nexusmods.com/v1/games/";
		String nexusURL = APIurl + string + myApiToken; 
		
		URL url = new URL(nexusURL);
		HttpURLConnection conn = (HttpURLConnection) url.openConnection();
		conn.setRequestProperty("apikey", apikey);
		 
		conn.setRequestMethod("GET");
		BufferedReader rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
		// Convert rd variable from BufferReader to String and store in variable called result. 
		String result = rd.lines().collect(Collectors.joining());
		return result;
	}
}
