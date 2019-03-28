import java.io.IOException;
import org.jibble.pircbot.*;


public class ChatBot extends PircBot {
	public ChatBot () {
		setName("testbot1");
	}
	public ChatBot (String name) {	//Constructor in case I want to dynamically choose the bot name.
		setName(name);
	}
	public void onMessage(String channel, String sender,
		String login, String hostname, String message){
		//Bot appreciation commands.
		if((message.contains("thank") || message.contains("thanks")) && (message.contains("bot"))) {
			sendMessage(channel, "I'll always have your back.");
		}else if(message.contains("best") && message.contains("bot")) {
			sendMessage(channel, "Well you're the best user, " + sender + ".");
		}
		//Checking for the user asking in plain English for the temperature in whatever city or zip, handling the possible question mark the user may end the request with.
		if(message.contains("What's the temperature in")) {
			if(message.contains("?")) {
				message = message.replace("?", "");
				try {
					sendMessage(channel, message.substring(26) + " is currently " + WeatherAPI.getWeather(WeatherAPI.getURL(message.substring(26))));
				} catch (IOException e) {
					e.printStackTrace();
				}
			}else {
				try {
					sendMessage(channel, message.substring(26) + " is currently " + WeatherAPI.getWeather(WeatherAPI.getURL(message.substring(26))));
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
		//Checking for "Giveme" command, followed by the specific command the user wants and the string to pass with it.
		if(message.contains("GiveMe") || message.contains("giveme") || message.contains("Giveme")) {
			if(message.contains("temperature")) {
				try {
					sendMessage(channel, WeatherAPI.getWeather(WeatherAPI.getURL(message.substring(19))));
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if(message.contains("TrendingMods") || message.contains("trendingmods")) {
					try {
						for(int i = 1; i <= 10; i++) {
						sendMessage(channel, NexusModsAPI.getMod(NexusModsAPI.getURL(message.substring(20)), i));
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
			}else if(message.contains("TrendingMod") || message.contains("trendingmod")) {
				try {
					String stringi = message.substring(19, 20);
					int i = Integer.parseInt(stringi);
					sendMessage(channel, NexusModsAPI.getMod(NexusModsAPI.getURL(message.substring(21)), i));
					
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
