using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;

public class LoadOnClick : MonoBehaviour {

	public void loadLevel(int level)
	{
		PlayerPrefs.SetInt ("kills", 0);
		PlayerPrefs.SetInt ("score", 0);
		PlayerPrefs.SetInt ("health", 10);
		PlayerPrefs.SetInt ("level", 1);
		SceneManager.LoadScene (level);
	}

	public void end()
	{
		Application.Quit ();
	}

}
