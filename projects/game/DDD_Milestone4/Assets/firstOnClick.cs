using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class firstOnClick : MonoBehaviour {
	public Text text;
	public bool saved;
	// Use this for initialization
	void Start () {
		text = GetComponentInParent<Text> ();
	}

	public void saveLevel()
	{

		PlayerPrefs.SetInt ("savedKills1", PlayerPrefs.GetInt ("kills"));
		PlayerPrefs.SetInt ("savedScore1", PlayerPrefs.GetInt ("score"));
		PlayerPrefs.SetInt ("savedHealth1", PlayerPrefs.GetInt ("health"));
		PlayerPrefs.SetInt ("savedLevel1", PlayerPrefs.GetInt ("level"));
		Debug.Log ("game saved");
		//		text.text = "Saved";
		saved = true;

	}
}
