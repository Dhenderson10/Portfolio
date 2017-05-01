using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class SaveOnClick : MonoBehaviour {
	public Text text;
	public bool saved;
	// Use this for initialization
	void Start () {
		text = GetComponentInParent<Text> ();
	}

	public void saveFirstLevel()
	{

			PlayerPrefs.SetInt ("savedKills1", PlayerPrefs.GetInt ("kills"));
			PlayerPrefs.SetInt ("savedScore1", PlayerPrefs.GetInt ("score"));
			PlayerPrefs.SetInt ("savedHealth1", PlayerPrefs.GetInt ("health"));
			PlayerPrefs.SetInt ("savedLevel1", PlayerPrefs.GetInt ("level"));
			Debug.Log ("game 1 saved");
			//		text.text = "Saved";
			saved = true;
	}

	public void saveSecondLevel()
	{
		PlayerPrefs.SetInt ("savedKills2", PlayerPrefs.GetInt ("kills"));
		PlayerPrefs.SetInt ("savedScore2", PlayerPrefs.GetInt ("score"));
		PlayerPrefs.SetInt ("savedHealth2", PlayerPrefs.GetInt ("health"));
		PlayerPrefs.SetInt ("savedLevel2", PlayerPrefs.GetInt ("level"));
		Debug.Log ("game 2 saved");
		//		text.text = "Saved";
		saved = true;

	}

	public void saveThirdLevel()
	{
		PlayerPrefs.SetInt ("savedKills3", PlayerPrefs.GetInt ("kills"));
		PlayerPrefs.SetInt ("savedScore3", PlayerPrefs.GetInt ("score"));
		PlayerPrefs.SetInt ("savedHealth3", PlayerPrefs.GetInt ("health"));
		PlayerPrefs.SetInt ("savedLevel3", PlayerPrefs.GetInt ("level"));
		Debug.Log ("game 3 saved");
		//		text.text = "Saved";
		saved = true;

	}

	public void quit()
	{
		SceneManager.LoadScene (0);
	}

	public void continueGame()
	{
		SceneManager.LoadScene (3);
	}

	public void loadFirstLevel()
	{

		PlayerPrefs.SetInt ("kills", PlayerPrefs.GetInt ("savedKills1"));
		PlayerPrefs.SetInt ("score", PlayerPrefs.GetInt ("savedScore1"));
		PlayerPrefs.SetInt ("health", PlayerPrefs.GetInt ("savedHealth1"));
		PlayerPrefs.SetInt ("level", PlayerPrefs.GetInt ("savedLevel1"));
		SceneManager.LoadScene (3);
		//		text.text = "Saved";
		saved = true;
	}

	public void loadSecondLevel()
	{

		PlayerPrefs.SetInt ("kills", PlayerPrefs.GetInt ("savedKills2"));
		PlayerPrefs.SetInt ("score", PlayerPrefs.GetInt ("savedScore2"));
		PlayerPrefs.SetInt ("health", PlayerPrefs.GetInt ("savedHealth2"));
		PlayerPrefs.SetInt ("level", PlayerPrefs.GetInt ("savedLevel2"));
		SceneManager.LoadScene (3);
		//		text.text = "Saved";
		saved = true;
	}

	public void loadThirdLevel()
	{

		PlayerPrefs.SetInt ("kills", PlayerPrefs.GetInt ("savedKills3"));
		PlayerPrefs.SetInt ("score", PlayerPrefs.GetInt ("savedScore3"));
		PlayerPrefs.SetInt ("health", PlayerPrefs.GetInt ("savedHealth3"));
		PlayerPrefs.SetInt ("level", PlayerPrefs.GetInt ("savedLevel3"));
		SceneManager.LoadScene (3);
		//		text.text = "Saved";
		saved = true;
	}




}
