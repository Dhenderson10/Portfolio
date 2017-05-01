using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class NextLevel : MonoBehaviour {

	public void loadLevel(int level)
	{
		SceneManager.LoadScene (level);
	}
}
