using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class transitionScript : MonoBehaviour {

	Text text;
	string[] phrases = new string[10];
	string chosen;
	// Use this for initialization
	void Start () {
		text = GetComponentInParent<Text> ();
		phrases[0] = "Hey";
		phrases[1] = "Keep it up";
		phrases[2] = "You're Gonna Lose";
		phrases[3] = "Love Games";
		phrases[4] = "Bye";
		phrases[5] = "Reported";
		phrases[6] = "gg wp no re";
		phrases[7] = "Enemies shoot ballz";
		phrases[8] = "Don't get hit";
		phrases[9] = "Git Gud";

		chosen = phrases [Random.Range (0, 10)];

	}
	
	// Update is called once per frame
	void Update () {
		text.text = "Level " + PlayerPrefs.GetInt ("level") + "\n\n" + chosen + "\n\n" + "Press Space To Continue";
		if (Input.GetKeyDown (KeyCode.Space) == true) {
			text.text = "Level " + PlayerPrefs.GetInt ("level") + "\n\n" + chosen + "\n\n" + "Loading...";
			SceneManager.LoadScene (3);
		}
	}
}
